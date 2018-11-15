/*************************************************************************
	> File Name: mergeSort.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月07日 星期三 08时42分15秒
 ************************************************************************/

#ifndef _MERGESORT_H
#define _MERGESORT_H

#include <functional>
#include <vector>
#include <algorithm>
// merge   算法导论 2.3.1
/*!
 *\parameter begin: begin...middle之间为已排好序列;
 *\parameter end: middle...end之间为已排好序列;
 *\parameter middle: begin...middle; middle...end都为已排好序列;
 *\parameter compare: 一个可调用对象,可用于比较两个对象的小于比较,默认为std::less<T>;
 *\retrun void;
 * 
 * 算法性能: O(N);
 * 归并思想: 假设对数组A[p...q...r]归并:
 *      --拷贝: 将数组A[p...q]拷贝到数组L; 将数组A[q+1...r]拷贝到数组R,
 *      --归并: 从左到右依次取L,R中较小的元素,存放到A中.
 * 非原址排序,归并需要额外的空间 O(N). 
*/
template<typename Iterator, typename CompareType = std::less<typename std::iterator_traits<Iterator>::value_type>>
void merge(const Iterator begin, const Iterator end, const Iterator middle, CompareType compare = CompareType())
{
    typedef typename std::iterator_traits<Iterator>::value_type T;      // 迭代器指向对象的类型
    if (std::distance(begin, middle) <= 0 || std::distance(middle, end) <= 0)   return;
    std::vector<T> result(begin, end);      // 暂存结果
    auto current = result.begin();
    auto left_current = begin;      // 左侧序列的当前比较位置
    auto right_current = middle;    // 右侧序列的当前比较位置
    while (left_current != middle && right_current != end){
        if (compare(*left_current, *right_current))
            *current++ = *left_current++;
        else
            *current++ = *right_current++;
    }
    // 当左侧被搬空的时候 
    if (left_current == middle && right_current != end)
        std::copy(right_current, end, current);
    // 当右侧被搬空的时候
    if (right_current == end && left_current != middle)
        std::copy(left_current, middle, current);
    // 把排序结果返回原来的序列
    std::copy(result.begin(), result.end(), begin);
}

// mergeSort    算法导论2.3.1
/*!
 * \parameter begin: 待排序序列的起始迭代器(也可以是指向数组某元素的指针)
 * \parameter end: 待排序序列的终止迭代器(也可以是指向数组某元素的指针)
 * \parameter compare: 一个可调用对象, 可用于比较两个对象小于, 默认std::less<T>
 * \return void
 *
 * 算法性能: O(NlogN);
 *      -- 在归并阶段的算法性能: O(logN);
 * 
 * 算法思想: 假设对数组A[p,...,r]排序:
 *      -- 分解: 将数组A[p,...,r]平均划分为两个数组A[p,...,q-1], A[q,...,r],依次划分直到每个子数组只有一个元素;
 *      -- 归并: 对排好序的两个数组A[p,...,q-1], A[q,...,r]进行合并;
 * 整个算法需要额外的空间 O(N);
*/
template<typename Iterator, typename CompareType = std::less<typename std::iterator_traits<Iterator>::value_type>>
void mergeSort(const Iterator begin, const Iterator end, CompareType compare = CompareType())
{
    auto size = std::distance(begin, end);
    if (size > 1){
        Iterator middle = begin + size / 2;
        mergeSort(begin, middle, compare);
        mergeSort(middle, end, compare);
        merge(begin, end, middle, compare);
    }
}
#endif
