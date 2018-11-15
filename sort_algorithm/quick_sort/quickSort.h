/*************************************************************************
	> File Name: quickSort.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月08日 星期四 20时49分32秒
 ************************************************************************/

#ifndef _QUICKSORT_H
#define _QUICKSORT_H

#include <functional>
#include <stdexcept>
#include <utility>
// partition: 算法导论第7章 快速排序算法中的划分算法.
/*
 * \parameter begin: 待划分序列的起始迭代器(也可以是指向数组中某元素的指针);
 * \parameter end: 待划分的终止迭代器(也可以是指向数组中某元素的指针);
 * \parameter partitioned_iter: 指定划分元素的对应的迭代器 (也可以是指向数组中某元素的指针);
 * \parameter compare: 一个可调用对象,可用于比较两个对象的小于(默认为std::less<T>);
 * \return 返回主元素的位置.
 *
 * 算法基本思想: 假设对数组A[p,...,r]划分:
 *      --划分的目的是找到一个主元假定q,使其满足:
 *              --A[p,...,q-1]的所有元素都小于A[q];
 *              --A[q+1,...,r]的所有元素都大于A[q].
 *   --假定划分主元为A[r];
 *   --循环不等式: 令current = begin, i = begin;
 *              --若A[current] < A[r], 则交换A[i]和A[current], i右移, current右移
 *              --若A[current] >= A[r], current右移.(进行下一个元素的判定).
 *
 * 时间复杂度: O(N).
 * 算法特性: 原址排序.
 *
 */
template<typename Iterator, typename CompareType = std::less<typename std::iterator_traits<Iterator>::value_type>>
Iterator partition(const Iterator begin, const Iterator end, 
                    const Iterator partitioned_iter, CompareType compare = CompareType())
{
    auto size = std::distance(begin, end);
    if (size <= 0)
        throw std::invalid_argument("decreate_key error: 输入序列的范围有误");
    auto x = *partitioned_iter;
    auto i = begin;
    std::swap(*partitioned_iter, *(end - 1));
    for (auto current = begin; current != end; ++current){
        if (compare(*current, x))
            std::swap(*i++, *current);
    }
    std::swap(*i, *(end - 1));
    return i;
}
// quickSort: 快速排序算法 算法导论第七章
/*
 * \parameter begin: 待划分序列的起始迭代器(也可以是指向数组中某元素的指针);
 * \parameter end: 待划分的终止迭代器(也可以是指向数组中某元素的指针);
 * \parameter compare: 一个可调用对象,可用于比较两个对象的小于(默认为std::less<T>);
 * \return void.
 *
 * 算法基本思想: 
 *      --分解: 数组A[p,...,r]被划分为两个(可能为空)子数组A[p,...,q-1]和A[q+1,...,r],
 *              使得A[p,...,q-1]中的每一个元素都小于等于A[q],而A[q]也小于等于A[q+1,...,r]中的
 *              每个元素;
 *      --解决: 通过递归调用快速排序,对子数组A[p,...,q-1]和A[q+1,...,r]进行排序;
 *      --合并: 由于子数组都是原址排序,所以不需要合并操作: 数组A[p,...,r]已经有序.
 *
 * 算法性能: 最坏情况下时间复杂度为O(N^2), 在元素互异的情况下,期望时间复杂度为O(NlogN).
 *
 */
template<typename Iterator, typename CompareType = std::less<typename std::iterator_traits<Iterator>::value_type>>
void quickSort(const Iterator begin, const Iterator end, CompareType compare = CompareType())
{
    auto size = std::distance(begin, end);
    if (size <= 1)
        return;
    auto partitioned_iter = partition(begin, end, end - 1, compare);
    quickSort(begin, partitioned_iter, compare);
    quickSort(partitioned_iter + 1, end, compare);
}
#endif
