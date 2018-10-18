/*************************************************************************
	> File Name: binarySearch.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年10月18日 星期四 13时07分43秒
 ************************************************************************/

#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H
// 在给定的从小到大排序好的数列中查找一个给定的数 
// ,如果存在返回下标如果不存在返回-1
#include <vector>

template <typename Comparable>
int binarySearch(const std::vector<Comparable> &a, const Comparable x)
{
    decltype(a.size()) low = 0, high = a.size() - 1;

    while (low <= high){
        auto mid = (high + low) / 2;
        if (a[mid] < x)
            low = mid + 1;
        else if (a[mid] > x)
            high = mid - 1;
        else
            return mid;
    }

    return -1;
}

#endif
