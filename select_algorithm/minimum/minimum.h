/*************************************************************************
	> File Name: minimum.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月11日 星期日 10时59分55秒
 ************************************************************************/

#ifndef _MINIMUM_H
#define _MINIMUM_H
#include <functional>
#include <cassert>
// minimum: 从一个集合中选择选择最小元素和最大元素的问题  算法导论9.1
/*
 * \parameter begin: 待排序序列的起始迭代器(也可以是指向数组中某元素的指针);
 * \parameter end: 待排序序列的终止迭代器(也可以是指向数组中某元素的指针);
 * \parameter compare: 一个可调用对象,可用于比较两个对象的小于,默认为std::less<T>;
 * \return 这个序列中的最值(typename std::iterator_traits<Iterator>::value_type).
 * 
 * 算法性能: 时间复杂度为: O(N).
 * 算法基本思想: 依次遍历集合中的每个元素,并记录下当前的最小元素.
 *
 */
template<typename Iterator, typename CompareType=std::less<typename std::iterator_traits<Iterator>::value_type>>
typename std::iterator_traits<Iterator>::value_type
minimum(const Iterator begin, const Iterator end, CompareType compare = CompareType())
{
    assert(begin != end);   // 保证输入的序列不是空序列
    typedef typename std::iterator_traits<Iterator>::value_type T;
    T min = *begin;
    for (auto current = begin; current != end; ++current){
        if (compare(*current, min))
            min = *current;
    }

    return min;
}
#endif
