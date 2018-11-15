/*************************************************************************
	> File Name: insertSort.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月06日 星期二 11时05分43秒
 ************************************************************************/

#ifndef _INSERTSORT_H
#define _INSERTSORT_H
// insertSort.h 算法导论第二章 2.1;
/* \parameter begin: 待排序序列的起始迭代器(也可以是指向数组中某元素的指针);
 * \parameter end: 待排序序列的终止迭代器(也可以是指向数组中某元素的指针);
 * \parameter compare: 一个可调用对象,可用于比较两个对象的小于比较,默认为std::less<T>;
 * \return void;
 *
 * 算法性能O(N^2).
 * 原址排序.
 * 算法具体思想: 插入排序对于少量元素的排序,它是一个有效的算法. 假设数组A[1,...,n]排序:
 * 设当前排序的元素是A[i],则A[1,...i-1]是排序好的,A[i]在A[1,...,i-1]中找到它的位置,然后插入其中.
*/
#include <functional>
template<typename Iterator, typename CompareType=std::less<typename std::iterator_traits<Iterator>::value_type>>
void insertSort(const Iterator begin, const Iterator end, CompareType compare=CompareType())
{
    // typedef typename std::iterator_traits<Iterator>::value_type T; // 迭代器指向对象的值的类型
    auto size = std::distance(begin, end);
    if (size <= 1)
        return;
    auto current = begin;
    while (++current != end){
        auto smallNext = current;       // 指向比*current小的元素中 最大的那一个a
        auto key = *current;
        while (smallNext != begin && compare(key, *(smallNext-1))){
            *smallNext = *(smallNext - 1);     // 后移
            --smallNext;
        }
        *smallNext = key;
    }
}
#endif
