/*************************************************************************
	> File Name: minqueue.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月07日 星期三 19时09分10秒
 ************************************************************************/

#ifndef _MINQUEUE_H
#define _MINQUEUE_H

#include <vector>
#include <memory>
#include <functional>
#include <utility>
#include <stdexcept>
//MinQueue: 最小优先队列  算法导论6.5
/*
 * 优先队列有两种形式:分别为最大优先队列和最小优先队列;这里关注如何基于最大堆
 * 实现最大优先队列.
 *
 * 优先队列是一种用来维护由一组元素构成的集合S的数据结构,其中的每一个元素都有
 * 一个相关的的值,称为关键字.一个最大优先队列支持以下操作:
 *      --insert(S,x): 把元素x插入集合S中.
 *      --min(S): 返回S中具有最小关键字的元素.
 *      --extract_min(S): 去掉并返回S中具有最小关键字的元素.
 *      --increase_key(S,x,k): 将元素x的关键字值增加到k,这里假设k的值不大于x的原
 *        关键字.
 *
 */
template<typename T, typename TkeyType>
class MinQueue
{
public:
    // 一个可调用对象类型,该类型的对象可以用于比较两个std::shared_ptr<T>的小于比较
    typedef std::function<bool (std::shared_ptr<T>, std::shared_ptr<T>)> CompareType;
    // 一个可调用对象,该类型的对象可用于获取std::shared_ptr<T>的关键字,并修改关键字(返回的是关键字的引用)
    typedef std::function<TkeyType&(std::shared_ptr<T>)> GetKeyType;
    // 显式构造函数
    /*
     * \parameter compare: 一个可调用对象,可用于比较两个std::shared_ptr<T>对象的小于比较
     * \parameter getKey: 一个可调用对象, 它的参数为std::shared_ptr<T>, 返回TkeyType&.通过它的返回值
     * 可以获取T的key,也可以修改T的key.
     *
     */
    MinQueue(CompareType compare, GetKeyType getKey): size(0), compare(compare), getKey(getKey) {}
    // 显式构造函数
    /*
     * \parameter reverse_size: 指定队列的初始容量;
     * \parameter compare: 一个可调用对象, 可用于比较两个std::shared_ptr<T>对象的小于比较;
     * \parameter getKey: 一个可调用对象, 它的参数为std::shared_ptr<T>,返回TkeyType&.通过它的返回值
     * 可以获取T的key,也可以修改T的key.
     *
     */
    MinQueue(std::size_t reverse_size, CompareType compare, GetKeyType getKey): size(0), compare(compare), getKey(getKey)
    {
        data.resize(reverse_size);
    }
    // min: 返回最小值
    /*
     * \return 最小值的引用
     * 算法基本思想: 根据最小堆的性质,堆的第一个元素就是最小值. 如果堆为空则返回一个空指针.
     *  --时间复杂度 O(1).
     *  --但是生成最小堆需要O(NlonN),从而算法复杂度为O(NlogN).
     */
    std::shared_ptr<T> min()
    {
        if (!size)
            return std::shared_ptr<T>();
        return data.at(0);      
    }
    // extract_min: 删除队列中的最小值, 并返回这个最小值.
    /*
     * \return 最小值的引用.
     * 算法基本思想: 根据最小堆的性质,堆中第一个元素就是最小值.
     *  --如果队列为空, 则返回一个空指针.
     *  --如果队列非空, 则执行如下操作:
     *      --交换队列的第一个元素和最后一个元素;
     *      --队列的size自减;
     *      --这时队列的首个元素违反了最小堆的特性, 因此执行heapify(0)保持性质;
     *      --返回旧的首元素
     *
     * 算法时间复杂度: O(lonN);
     * 堆的建立时间: O(NlonN); 总体时间复杂度, O(NlonN) + O(lonN);
     *
     * 一旦队列长度不足容量的1/4,将队列容量设置为队列长度的一倍(为了防止特殊情况,如size=0,
     * 此时将队列容量设置为队列长度的一倍).(主要作用为减少内存消耗)
     */
    std::shared_ptr<T> extract_min()
    {
        if (!size)
            return std::shared_ptr<T>();
        auto result = data.at(0);
        data.at(0) = data.at(size-1);
        --size;
        heapify(0);
        if (size <= data.size() / 4)
            data.resize(size * 2 + 2);
        return result;
    }
    // insert: 向队列中插入一个元素
    /*
     * \parameter element: 待插入元素,如果元素为空指针则直接返回;
     * \return: 插入的元素在队列中的位置.若元素为空指针则返回-1.
     *
     * 在插入之前首先判断队列是否已满.若队列已满,则将'data'扩容为'size*2+1'.
     *  --若'size=data.size()'则说明队列已满.
     * 
     * 插入过程为:
     *  --保留待插入元素的'key',同时将待插入元素的'key'设置为无穷大,并将待插入元素插入到队尾.
     *  --执行'decreate_key(...)'操作.
     *
     *  --一旦队列已满,则将队列容量增加为队列长度的一倍(防止极端情况,如size=0,此时将队列容量设置为队列长度一倍加2)
     *  --时间复杂度: O(logN);
     *  --原地操作.
     *
     */
    int insert(std::shared_ptr<T> element)
    {   
        if (!element) return -1;    // 参数指针为一个空指针
        if (size == data.size())    data.resize(size*2+2);      // 扩容
        int index = size;
        ++size;     // 增加一个元素后size自增
        data[index] = element;  // 将元素放在队列的最后一个位置
        TkeyType& k = getKey(element);
        getKey(data.at(index)) = k;
        index = decreate_key(index, k);
        return index;
    }
    // decreate_key: 缩减队列中某个元素的'key'
    /*
     * \parameter element_index: 待缩减元素的下标;
     * \parameter new_key: 待缩减元素的新'key',类型为TkeyType;
     * \return  符合小堆性质的插入点(std::size_t).
     *
     * 缩减之前先判断缩减是否有效,若无效则抛出异常.
     *  --若'element_index'超过了队列大小,则抛出key;
     *  --若'new_key'大于等于待缩减元素的'key',则抛出异常.
     *
     * 缩减过程为:
     *  --将待缩减元素的'key'赋值为新值
     *  --不断的将该元素与父节点比较:
     *      --若父节点较小,则终止比较过程;
     *      --若父节点较大,则交换当前节点与父节点,并将当前节点与当前节点的父节点进行下一轮的比较;
     *      --若当前节点已近是队列首元素,则终止循环过程.
     *
     *  --时间复杂度: O(logN);
     *  --原地操作.
     *
     */
    std::size_t decreate_key(std::size_t element_index, TkeyType new_key)
    {
        if (element_index >= size)
            throw std::invalid_argument("decreate_key error: element_index mush less than size!");
        if (new_key > getKey(data.at(element_index)))
            throw std::invalid_argument("decreate_key error: new_key less data.at(element_index)->key!");
        getKey(data.at(element_index)) = new_key;
        bool valid = true;
        while(element_index != 0){
            auto pIndex = parentIndex(element_index, valid);
            if (!valid) break;  // 父节点不存在的情况
            if (compare(data.at(pIndex), data.at(element_index)))   break;  // 最小堆的性质满足
            std::swap(data.at(pIndex), data.at(element_index));
            element_index = pIndex;
        }
        return element_index;
    }
    
private:
    // 数据结构
    std::vector<std::shared_ptr<T>> data;   // 最小优先级队列数据
    std::size_t size;   // 堆大小
    CompareType compare;    // 一个可调用对象,可用于两个std::shared_ptr<T>对象的小于比较
    GetKeyType getKey;      // 一个可调用对象,可用于获取std::shared_ptr<T>的关键字,并修改关键字(返回的是关键字的引用)
    
    // 隐藏的成员函数
    // parentIndex: 返回一个节点的父节点位置
    /* 
     * \parameter elementIndex: 子节点的位置;
     * \parameter valid: 一个bool&值,用于返回, 指示父节点是否有效;
     * \return 父节点的位置(std::size_t).
     *  
     *  --超出堆大小的节点,其父节点无效.
     *
     */
    std::size_t parentIndex(std::size_t elementIndex, bool &valid)
    {
        if (elementIndex >= size){
            valid = false;
            return 0;
        }
        valid = true;   // 有效结果
        if (elementIndex == 0)
            return 0;
        else
            return (elementIndex - 1) / 2;
    }
    // lchildIndex: 返回一个节点的左孩子的节点位置
    /*
     * \parameter elementIndex: 父节点的位置;
     * \parameter valid: 一个bool &值, 用于返回,指示左孩子节点是否有效;
     * \return 左孩子节点的位置(std::size_t).
     *
     *  --size<=1 不存在左孩子节点.
     *  --当左节点超过堆大小时,无效.
     *
     */
    std::size_t lchildIndex(std::size_t elementIndex, bool &valid)
    {
        if (size <= 1){
            valid = false;     // 数组元素太少,无效结果
            return 0;
        }
        if (elementIndex > (size - 2)/2){
            valid = false;
            return 0;
        }
        valid = true;
        return (2 * elementIndex + 1);
    }
    // rchildIndex: 返回一个节点的右孩子节点位置
    /*
     * \parameter elementIndex: 父节点的位置;
     * \parameter valid: 一个bool&值,用于返回,右孩子节点是否有效;
     * \return 右孩子节点的位置(std::size_t).
     *
     *  --size<=2 不存在右孩子节点.
     *  --当右孩子节点超过堆大小时,无效.
     *
     */
    std::size_t rchildIndex(std::size_t elementIndex, bool &valid)
    {
        if (size <= 2){
            valid = false;  // 数组元素太少,无效结果
            return 0;
        }
        if (elementIndex > (size - 3) / 2){
            valid = false;
            return 0;
        }
        valid = true;
        return (2 * elementIndex + 2);
    }
    // heapify: 维持堆的特性
    /*
     * \parameter elementIndex: 要维持以该节点为根节点的子堆的特性;
     * \return void.
     *
     * 算法基本思想: 首先调用比较该节点与左右子节点的最小值. 如果最小值
     * 为它本身,则维持了性质,返回; 如果最小值不是它本身,那么必然就在左,右
     * 节点之一.将该最小节点(假设为左节点)交换到根节点, 然后以左节点递归调用
     * heapify操作.
     *
     * 时间复杂度为:O(logN), 如果堆的高为l那么时间复杂度为O(l).
     *  --原址操作.
     *
     */
    void heapify(std::size_t elementIndex)
    {
        if (elementIndex >= size)
            return;
        auto minIndex = elementIndex;
        bool left_valid = true;
        bool right_valid = true;
        auto leftIndex = lchildIndex(elementIndex, left_valid);
        auto rightIndex = rchildIndex(elementIndex, right_valid);
    
        // 对左孩子节点分析
        if (left_valid){
            if (compare(data.at(leftIndex), data.at(minIndex)))
                minIndex = leftIndex;
        }

        // 对右孩子节点分析
        if (right_valid){
            if (compare(data.at(rightIndex), data.at(minIndex)))
                minIndex = rightIndex;
        }
        
        // 最小值不为本身
        if (minIndex != elementIndex){
            std::swap(data.at(elementIndex), data.at(minIndex));
            heapify(minIndex);
        }
    }
    // buildHeap: 堆的建立
    /*
     * \return void;
     * 算法基本思想: 从后一半的元素开始依次向前调用heapify操作.
     *
     *   --时间复杂度:O(NlogN);
     *   --原址操作.
     *
     */
    void buildHeap()
    {
        if (size <= 1)
            return;
        int index = (size - 1) / 2;
        while (index >= 0){
            heapify(index);
            --index;
        }
    }
};
#endif
