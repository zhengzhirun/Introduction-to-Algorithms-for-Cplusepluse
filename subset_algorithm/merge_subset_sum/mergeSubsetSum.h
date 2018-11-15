/*************************************************************************
	> File Name: mergeSubsetSum.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月06日 星期二 19时25分56秒
 ************************************************************************/

#ifndef _MERGESUBSETSUM_H
#define _MERGESUBSETSUM_H
// 寻找最大相连子序列和的递归算法(该算法同时适应求最小相连子序列的递归算法,只需要修改compare即可)  
// 数据结构与算法分析--C++语言描述 2.4.3
// 算法导论 4.1

/*
 *\parameter begin: 待计算序列的起始迭代器;
 *\parameter end: 待计算序列的终止迭代器;
 *\parameter compare: 一个可调用的对象,可用于比较两个对象的小于,默认为std::less<T>;
 *\return std::iterator_traits<Iterator>::value_type;
 *
 * 算法性能O(NlogN)
 * 
 * 算法具体思想: 把一整个序列分成两个部分,分别在左侧求解最大相连子序列和,在右侧计算
 * 出最大相连子序列和.整个序列的最大子序列和为左侧最大值,右侧最大值,横跨左右和,
 * 三个中的最大值;
 *
*/
#include <iostream>
#include <functional>
template<typename Iterator, typename CompareType = std::less<typename std::iterator_traits<Iterator>::value_type>>
typename std::iterator_traits<Iterator>::value_type
megre(Iterator begin, Iterator end, CompareType compare=CompareType())
{
    typedef typename std::iterator_traits<Iterator>::value_type T;
    // 基准情形
    if (std::distance(begin, end) <= 1)
        return *begin;
    // 递归情形
    auto center = begin + (std::distance(begin, end)) / 2;
    T maxLeftSum = megre(begin, center, compare);
    T maxRightSum = megre(center+1, end, compare);

    // 左侧
    T maxLeftBounderSum = *center;
    T leftBounderSum = *center - *center;
    for (auto middle = center; middle != begin-1; --middle){
        leftBounderSum += *middle;
        if (compare(maxLeftSum, leftBounderSum))
            maxLeftBounderSum = leftBounderSum;
    }

    // 右侧
    T maxRightBounderSum = *(center+1);
    T rightBounderSum = *(center+1) - *(center+1);
    for (auto middle = center+1; middle != end; ++middle){
        rightBounderSum += *middle;
        if (compare(maxRightSum, rightBounderSum))
            maxRightBounderSum = rightBounderSum;
    }
    
    // 返回三种情况的最大值
    auto max = maxLeftSum;
    if (compare(max, maxRightSum))
        max = maxRightSum;
    if (compare(max, maxLeftBounderSum + maxRightBounderSum))
        max = maxLeftBounderSum + maxRightBounderSum;

    return max;
}
#endif
