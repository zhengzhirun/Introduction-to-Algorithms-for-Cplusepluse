/*************************************************************************
	> File Name: originalSubsetSum.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月06日 星期二 16时40分53秒
 ************************************************************************/

#ifndef _ORIGINALSUBSETSUM_H
#define _ORIGINALSUBSETSUM_H
// 寻找最大相连子序列和的暴力算法(该算法同时适用于求最小相连子序列和,只需要修改compare即可) 
// 数据结构与算法分析--C++语言描述 2.4.3
// 算法导论 4.1
/* !
 *\parameter begin: 待计算序列的起始迭代器(也可以是指向数组中某元素数组的指针);
 *\parameter end: 待计算序列的终止迭代器(也可以是指向数组中某元素数组的指针);
 *\parameter compare: 一个可调用的对象,可用于比较两个对象的小于,默认为std::less<T>;
 *\return std::iterator_traits<Iterator>::value_type
 *算法性能O(N^2)
 *
 *算法的具体思想: 依次遍历序列中的子序列,然后计算子序列和,给出最大的值.
*/
#include <iostream>
#include <functional>
template<typename Iterator, typename CompareType = std::less<typename std::iterator_traits<Iterator>::value_type>>
typename std::iterator_traits<Iterator>::value_type
original(Iterator begin, Iterator end, CompareType compare=CompareType())
{
    auto size = std::distance(begin, end);
    if (size < 1){
        std::cerr << "您输入的序列范围有误.\n";
        return -1;
    }
    typedef typename std::iterator_traits<Iterator>::value_type T;
    T goodSum = *begin;
    while (begin != end){
        T subsetSum = *begin - *begin;
        for (auto current = begin; current != end; ++current){
            subsetSum += *current;
            if (compare(goodSum, subsetSum))
                goodSum = subsetSum;
            }
            ++begin;
        }
    return goodSum;
}
#endif
