/*************************************************************************
	> File Name: goodSelect.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月12日 星期一 09时57分57秒
 ************************************************************************/

#ifndef _GOODSELECT_H
#define _GOODSELECT_H

#include <cassert>
#include <vector>
#include <utility>
// insertSort: 插入排序  算法导论2.1
/*
 * \parameter begin: 待排序序列的起始迭代器(也可以是指向数组中某元素的指针);
 * \parameter end: 待排序序列的终止迭代器(也可以是指向数组中某元素的指针);
 * \parameter compare: 一个可调用对象,可用于比较两个对象的小于比较,默认为std::less<T>;
 * \return void.
 *
 * 算法性能: O(N^2), 原址排序.
 * 算法基本思想: 插入排序是对少量元素的排序,它是一个有效的算法.假设数组A[1,...,n]排序:
 *               设当前排序元素是A[i],则A[1,...,i-1]是排序好的,A[i]在A[1,...,i-1]中找
 *               到它的位置,然后插入其中.
 *
 */
template<typename Iterator, typename CompareType = std::less<typename std::iterator_traits<Iterator>::value_type>>
void insertSort(const Iterator begin, const Iterator end, CompareType compare = CompareType())
{
    auto size = std::distance(begin, end);
    assert(size > 0);
    for (auto current = begin; current != end; ++current){
        auto smallNext = current;       // 指向比*current小的元素中,最大的那一个
        auto key = *current;
        while (smallNext != begin && compare(key, *(smallNext - 1))){
            *smallNext = *(smallNext - 1);  // 后移
            --smallNext;
        }
        *smallNext = key;
    }
}
// partition: 快速排序算法中的划分算法  算法导论7.1 随机化版本在7.3
/*
 * \parameter begin: 待划分序列的起始迭代器(也可以是指向数组中某元素的指针);
 * \parameter end: 待划分序列的终止迭代器(也可以是指向数组中某元素的指针);
 * \parameter partitioned_iter: 指定划分元素对应的迭代器(也可以是指向数组中某元素的指针);
 * \parameter compare: 一个可调用对象,可用于比较两个对象的小于比较, 默认为std::less<T>;
 * \retrun void.
 *
 * 算法性能: 时间复杂度为O(N), 原址操作.
 * 算法基本思想: 假定对数组A[p,...,r]划分:
 *      --划分的目的是找到一个主元素假定q,使其满足:
 *          --A[p,...,q-1]的所有元素都小于A[q];
 *          --A[q+1,...,r]的所有元素都大于A[q].
 *      --假定主元为A[r];
 *      --循环不等式: 令current=begin, i=begin;
 *              --若A[current] < A[r], 则交换A[r]和A[current], i右移, current右移;
 *              --若A[current] > A[r], current右移.(进行下一个元素的判定).
 *
 */
template<typename Iterator, typename CompareType = std::less<typename std::iterator_traits<Iterator>::value_type>>
Iterator partition(const Iterator begin, const Iterator end, 
                   const Iterator partitioned_iter, CompareType compare = CompareType())
{
    assert(std::distance(begin, partitioned_iter) >= 0 && std::distance(partitioned_iter, end) > 0 
           && std::distance(begin, end) > 0);
    std::swap(*partitioned_iter, *(end - 1));   // 把待定主元交换到序列最后一个元素
    auto i = begin;
    for (auto current = begin; current != (end - 1); ++current){
        if (compare(*current, *(end - 1)))
            std::swap(*i++, *current);
    }
    std::swap(*i, *(end - 1));

    return i;
}
// goodSelect: 最坏情况下为线性时间的选择算法  算法导论9.3
/*
 * \parameter begin: 待选择序列的起始迭代器(也可以是指向数组中某元素的指针);
 * \parameter end: 待选择序列的终止迭代器(也可以是指向数组中某元素的指针);
 * \parameter rank: 指定选取的顺序数,0为最小,1为次小,...依次类推;
 * \parameter compare: 一个可调用对象,可以用于对两个对象的小于比较,默认为std::less<T>;
 * \return 第rank小的元素.
 *
 * 算法基本思想: 
 *      --1.将输入数组的n个元素划分为n/5组,每组5个元素,且最多只有一组由剩下的n%5个元素组成;
 *      --2.寻找这n/5组中每一组的中位数: 首先对每组元素进行插入排序,然后确定每组有序元素的中位数;
 *      --3.对第2步中找出的这n/5个中位数,递归调用goodSelsct以找出其中位数x(如果有偶数个中位数,为了方便,约定x是较小的中位数);
 *      --4.利用修改过的partition版本,按中位数的中位数x对输入数组进行划分.让k比划分的低区中的元素数目多1,
 *          因此x是第k小的元素,并且有n-k个元素在划分的高区;
 *      --5.如果i=k,则返回x.如果i<k,则在低区递归调用goodSelect来找出第i小的元素.如果i>k,则在高区递归查找第i-k小的元素.
 *
 * 算法性能: 最坏情况下运行时间为O(N), 非原地操作.
 *
 */
template<typename Iterator, typename CompareType = std::less<typename std::iterator_traits<Iterator>::value_type>>
typename std::iterator_traits<Iterator>::value_type
goodSelect(const Iterator begin, const Iterator end, 
           typename std::iterator_traits<Iterator>::difference_type rank, CompareType compare = CompareType())
{
    typedef typename std::iterator_traits<Iterator>::value_type T;
    auto size = std::distance(begin, end);
    assert(size > 0);
    assert(rank < size);
    // 基准情形
    if (size == 1)
        return *begin;
    // 将序列划分为5个元素一组的区间, 最后一组可能不满5个元素;对每组进行排序,取出其中值放入vector中
    auto iter = begin;
    std::vector<T> middle_nums;
    while (iter < end){
        auto from = iter;
        auto to = from + 5;
        if (to > end)
            to = end;
        insertSort(from, to, compare);
        middle_nums.push_back(*(from+(to-from-1)/2));
        iter += 5;
    }
    // 取出这些中值的中值
    T mid_of_middles = goodSelect(middle_nums.begin(), middle_nums.end(), middle_nums.size()/2, compare); // 所有中值的中值
    iter = begin;
    while (std::distance(iter, end) > 0 && *iter != mid_of_middles)     // 得到中值的中值在原序列中的位置
        iter++;
    // 划分
    auto mid_of_middles_iter = partition(begin, end, iter, compare);    // 以中值的中值作为一个划分值
    // 判别
    auto mid_of_middles_rank = std::distance(begin, mid_of_middles_iter);   // 中值的中值在划分之后的排序
    if (mid_of_middles_rank == rank)    // 找到了该排位的数
        return *mid_of_middles_iter;
    else if (mid_of_middles_rank < rank) // 已知某排位的数位较低,则指定排位数的元素在它的右侧
        // mid_of_middles_iter + 1,则找右侧的第rank-mid_of_middles_rank-1位
        return goodSelect(mid_of_middles_iter + 1, end, rank - mid_of_middles_rank - 1, compare);
    else
        return goodSelect(begin, mid_of_middles_iter, rank, compare);    
}
#endif
