/*************************************************************************
	> File Name: onlineSubsetSum.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月06日 星期二 21时11分49秒
 ************************************************************************/

#ifndef _ONLINESUBSETSUM_H
#define _ONLINESUBSETSUM_H
// 寻找最大相连子序列和的初始算法(该算法同时也适用于求最小相连子序列和,只需要修改compare即可)
// 数据结构与算法分析--C++语言描述 2.4.3
// 算法导论4.1
/* 
 *\parameter begin: 待计算序列的起始迭代器(也可以指向数组中某元素数组的指针);
 *\parameter end: 待计算序列的终止迭代器(也可以指向数组中某元素数组的指针);
 *\parameter compare: 一个可调用的对象,可用于比较两个对象的小于,默认为std::less<T>;
 *\return std::iterator_traits<Iterator>::value_type;
 *
 *算法性能: O(N)
 *算法的具体思想: 明确可知: 在取最小相连序列和的时候,当 thisSsum > maxSum && thisSum > 0
 *则最小序列和不可能以thisSum开头; 同理在取最大相连序列和的时候, 当thisSum < maxSum && thisSum <0
 *则最大序列和不可能以thisSum开头;
*/
#include <iostream>
#include <functional>
template<typename Iterator, typename compareType = std::less<typename std::iterator_traits<Iterator>::value_type>>
typename std::iterator_traits<Iterator>::value_type
online(Iterator begin, Iterator end, compareType compare=compareType())
{
    auto size = std::distance(begin, end);
    if (size < 1){
        std::cerr << "您所输入的序列范围有误\n";
        return -1;
    }

    typedef typename std::iterator_traits<Iterator>::value_type T;
    T maxSum = *begin;
    T thisSum = *begin - *begin;
    for (auto index = begin; index != end; ++index){
        thisSum += *index;
        if (compare(maxSum, thisSum))
            maxSum = thisSum;
        else if (compare(thisSum, maxSum) && compare(thisSum, *begin - *begin))
                thisSum = *begin - *begin;
    }

    return maxSum;
}

#endif
