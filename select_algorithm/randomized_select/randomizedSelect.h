/*************************************************************************
	> File Name: randomizedSelect.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月11日 星期日 15时08分33秒
 ************************************************************************/

#ifndef _RANDOMIZEDSELECT_H
#define _RANDOMIZEDSELECT_H

#include <cassert>
#include <functional>
#include <utility>
#include <random>
// randomizedPartition: 快速排序算法中的划分算法  算法导论7.1
/*
 * \parameter begin: 待选取序列的起始迭代器(也可以是指向数组中某元素的指针);
 * \parameter end: 待选取序列的终止迭代器(也可以是指向数组中某元素的指针);
 * \parameter partitioned_iter: 指定划分元素对应的迭代器(也可以是指向数组中某元素的指针);
 * \return 返回主元素的指针.
 *
 * 算法基本思想: 假定对数组A[p,...,r]划分:
 *      --划分的目的是找到一个主元假定q,使其满足:
 *          --A[p,...,q-1]的所有元素都小于A[q];
 *          --A[q+1,...,r]的所有元素都大于A[q].
 *      --假定主元为A[r];
 *      --循环不等式: 令current=begin, i=begin;
 *              --若A[current] < A[r], 则交换A[r]和A[current], i右移, current右移;
 *              --若A[current] > A[r], current右移.(进行下一个元素的判定).
 * 算法时间复杂度: O(N).
 *
 */
template<typename Iterator, typename CompareType = std::less<typename std::iterator_traits<Iterator>::value_type>>
Iterator randomizedPartition(const Iterator begin, const Iterator end, 
                             const Iterator partitioned_iter, CompareType compare = CompareType())
{
    assert(begin != end);   // 序列不能是一个空序列
    assert(std::distance(begin, partitioned_iter) >= 0 && std::distance(partitioned_iter, end) > 0);
    
    auto x = *partitioned_iter;     
    auto i = begin;
    std::swap(*partitioned_iter, *(end - 1));   // 元素交换
    for(auto current = begin; current != end; ++current){
        if (compare(*current, x))
            std::swap(*i++, *current);
    }
    std::swap(*i, *(end - 1));

    return i;
}
// randomiezdSelect: 随机选择算法(期望为线性时间的选择算法)
/*
 * \parameter begin: 待选取序列的起始迭代器(也可以是指向数组中某元素的指针);
 * \parameter end: 待选取序列的终止迭代器(也可以是指向数组中某元素的指针);
 * \parameter minIndex: 选取排序第几的元素(0表示最小(或最大),1表示次小(次大),依次类推);
 * \parameter compare: 一个可调用的对象,可用于比较两个对象的小于比较,默认为std::less<T>;
 * \return 排序minIndex的元素.
 *
 * 算法基本思想: 假设对数组A[p,...,r]选择, 选择第k小的元素:
 *          --随机选择主元: 随机选取数组一个下标q,A[q]作为划分元素;
 *          --划分: 利用A[q]划分数组, 获得数组A[q]在序列是第m小;
 *          --判定: 
 *              --若m==k, 则找到了这个元素, 返回A[q];
 *              --若m<k, 则说明指定的元素在A[q+1,...,r]中,且位于这个新数组的k-m-1小,
 *                此时递归调用randomiezd_select(q+1, end, k-m-1);
 *              --若m>k, 则说明指定的元素在A[p,...,q-1]中,且位于这个新数组的的k小,
 *                此时递归调用randomiezdSelect(begin, q, k);
 * 时间复杂度: 最坏的情况为 O(N^2), 期望时间复杂度为 O(N);
 *
 * 算法特性: 原地操作.
 *
 */
template<typename Iterator, typename CompareType = std::less<typename std::iterator_traits<Iterator>::value_type>>
typename std::iterator_traits<Iterator>::value_type
randomiezdSelect(const Iterator begin, const Iterator end, 
                 std::size_t minIndex, CompareType compare = CompareType())
{
    auto size = std::distance(begin, end);
    assert(size >= 0);  // 序列不能是一个空序列
    assert(size >= minIndex);   
    // 基准情形
    if (size <= 1)
        return *begin;
    std::default_random_engine e;
    std::uniform_int_distribution<unsigned> u(0,size);
    auto partitioned_iter = randomizedPartition(begin, end, begin + u(e), compare);
    auto smallerNumbers = std::distance(begin, partitioned_iter);
    if (minIndex == smallerNumbers)
        return *partitioned_iter;
    if (minIndex < smallerNumbers)
        return randomiezdSelect(begin, partitioned_iter, minIndex, compare);
    else if (minIndex > smallerNumbers)
        return randomiezdSelect(partitioned_iter + 1, end, minIndex - smallerNumbers - 1);      

}
#endif
