/*************************************************************************
	> File Name: heapSort.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月07日 星期三 12时39分23秒
 ************************************************************************/

#ifndef _HEAPSORT_H
#define _HEAPSORT_H

#include <iostream>
#include <functional>
#include <utility>
// HeapSort: 用于堆排序的堆, 算法导论 6.1~6.4
/* 
 * 堆排序的算法思想: 假设对数组A[p,...,r]排序
 *      --首先对数组建成一个最大堆.然后第一个元素就是堆中的最大元素.
 *      --将第一个元素与最后一个元素交换,同时堆的规模缩减1(对剩下的元素重新
 *      --建立一个新堆),再将堆维持为最大堆的性质.不断循环最后得到一个排序好
 *      --的序列.
 * 
 * 算法性能: O(NlogN), 原址排序;
 * 在算法导论 8.1中证明了: (定理8.1)在最坏的情况下任何比较排序算法都需要做\omega(NlogN)次比较.
 *
 * 堆排序和归并排序都是渐进最优的比较排序算法.
 *
*/
template<typename Iterator, typename CompareType = std::less<typename std::iterator_traits<Iterator>::value_type>>
class HeapSort
{
public:
    HeapSort(): from(0), size(0) {  }
    HeapSort(Iterator begin, std::size_t num): from(begin), size(num) {  }
    HeapSort(const HeapSort &hs): from(hs.from), size(hs.size) {  }    // 拷贝构造函数
    HeapSort& operator= (const HeapSort &hs)
    {
        from = hs.from;
        size = hs.size;

        return *this;
    }
    ~HeapSort() = default;      // 析构函数
    // operator() 堆排序算法启动.
    /*
     * \parameter begin: 待排序序列的起始迭代器(也可以是指向数组中某元素的指针);
     * \parameter end: 待排序序列的终止迭代器(也可以是指向数组中某元素的指针);
     * \parameter compare: 一个可调用对象,可用于两个对象的小于比较,默认std::less<T>;
     * \return void.
     *
     */
    void operator() (const Iterator begin, const Iterator end, CompareType compare = CompareType())
    {
        from = begin;
        size = std::distance(begin, end);
        buildMaxHeap(compare);  // 建立最大堆
        while (size > 0){
            std::swap(*from, *(from + size - 1));
            --size;
            heapify(0, compare);
        }
    }

private:   
    // 数据结构
    Iterator from;      // 堆根节点的位置
    std::size_t size;   // 堆大小
    
    // 私有成员函数
    // parentIndex: 返回一个节点父节点的位置.
    /*
     * \parameter elementIndex: 子节点位置;
     * \parameter valid: bool值,用于返回,指示父节点是否有效;
     * \return 父节点的位置(std::size_t).
     *
     *  --根据最大堆的性质,一个子节点elementIndex的父节点的位置为(elementIndex-1)/2
     *  --超出堆大小的节点,其父节点无效.
     *  
     */
    std::size_t parentIndex(std::size_t elementIndex, bool &valid)
    {
        if (elementIndex >= size){
            valid = false;      // 无效结果
            return 0;
        }
        valid = true;   // 有效结果
        if (elementIndex == 0)  
            return 0;   // 根节点的父节点就是自己
        else    
            return (elementIndex - 1) / 2;
    }

    // lchildIndex: 返回一个节点的左子节点位置.
    /* !
     * \parameter elementIndex: 节点位置;
     * \parameter valid: bool值,用于返回指示子节点是否有效;
     * \return 左子节点的位置(std::size_t)
     *
     *  --根据最大堆的性质,一个节点elementIndexde左子节点的位置为:(elementIndexde*2+1)
     *  --当最大堆大小为0,1时,它没有左子节点,左子节点无效
     *  --当左子节点超过堆大小时, 无效
     *
     */
    std::size_t lchildIndex(std::size_t elementIndex, bool &valid)
    {
        if (size < 2){
            valid = false;  // 数组元素太少无效结果
            return 0;
        }
        if (elementIndex > (size - 2) / 2){
            valid = false;  // 超出范围,无效
            return 0;
        }
        valid = true;
        return (elementIndex * 2 + 1);
    }

    // rchildIndex: 返回一个节点右节点的位置.
    /* !
     * \parameter elementIndex: 节点位置;
     * \parameter valid: bool值, 用于返回指示子节点是否有效;
     * \return 右节点的位置(std::size_t)
     *
     *  --根据最大堆的性质,一个节点elementIndex右节点的位置为:(elementIndexde*2+2)
     *  --当最大堆大小超过0,1时,它没有右节点,右节点无效
     *  --当右节点超过堆大小时,无效.
     *
     */
    std::size_t rchildIndex(std::size_t elementIndex, bool &vaild)
    {
        if (size < 3){
            vaild = false;  // 数组元素太少,无效结果
            return 0;
        }
        if (elementIndex > (size - 3) / 2){
            vaild = false;  // 超出范围,无效结果
            return 0;
        }
        vaild = true;
        return (elementIndex * 2 + 2);
    }

    // heapify: 维护堆的性质(最大堆)
    /*
     * \parameter elementIndex: 要维护以该节点为根节点子堆的性质;
     * \parameter compare: 一个可调用对象,用于两个对象的小于比较,默认为std::less<T>;
     * \return void
     *
     * 算法思想: 首先调用比较该节点与左右孩子节点的最大值.如果最大值为节点本身那么就
     * 维持了最大堆的性质,返回; 如果最大值不是它本身,那么必然是左,右孩子节点之一,将该
     * 最大节点(假设为左孩子节点)交换到根节点,然后以左孩子节点递归调用heapify操作.
     *
     * 算法复杂度: O(logN), 对于一个树高为h的节点来说,时间复杂度为O(h).
     * 原址操作.
     *
     */
    void heapify(std::size_t elementIndex, CompareType compare = CompareType())
    {
        if (elementIndex >= size)
            return;
        auto maxIndex = elementIndex;
        bool left_valid = true;
        bool right_valid = true;
        auto leftIndex = lchildIndex(elementIndex, left_valid);     // 给出左孩子节点的位置
        auto rightIndex = rchildIndex(elementIndex, right_valid);   // 给出右孩子节点的位置

        // 如果左孩子节点存在
        if (left_valid){
            if (compare(*(from + maxIndex), *(from + leftIndex)))
                maxIndex = leftIndex;
        }

        // 如果右孩子节点存在
        if (right_valid){
            if (compare(*(from + maxIndex), *(from + rightIndex)))
                maxIndex = rightIndex;
        }

        // 如果最大节点位置不是本身
        if (maxIndex != elementIndex){
            std::swap(*(from + elementIndex), *(from + maxIndex));
            heapify(maxIndex, compare);     // 递归调用
        }
    }

    // buildMaxHeap: 建堆
    /*
     * \parameter compare: 一个可调用的对象,可用于两个对象的小于比较,默认为std::less<T>;
     * \return void.
     *
     * 算法性能: 时间复杂度为: O(NlogN).
     *   --原地操作.
     * 算法思想: 从后一半元素依次向前调用heapify. 子数组A[n/2+1,...,n]的元素都是树的叶节点.
     *
     */
    void buildMaxHeap(CompareType compare = CompareType())
    {
        if (size <= 1)
            return;
        int index = (size - 1) / 2;
        while (index >= 0){
            heapify(index, compare);
            --index;
        }
    }
};
#endif
