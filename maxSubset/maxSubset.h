/*************************************************************************
	> File Name: maxSubset.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年10月17日 星期三 10时25分03秒
 ************************************************************************/

#ifndef MAXSUBSET_H
#define MAXSUBSET_H

#include <iostream>
#include <vector>

// 最大子序列和问题求解
// 给定的问题: 给定(可能是负的)整数A_1, A_2, ..., A_N, 求 
// sum_{k = i}^{j} A_k的最大值.(为了方便起见,如果所有的整数均为负值,则
// 最大子序列的和为0)

// 最大相连子序列和立方级(O(n^3))算法
int maxSubSum1(const std::vector<int> &);

// 最大相连子序列和平方级(O(n^2))算法
int maxSubSum2(const std::vector<int> &);

// 最大相连子序列和递归算法(O(nlog(n)))
int maxSubSum3(const std::vector<int> &);

// 线性时间最大相连子序列和算法(O(n))
int maxSubSum4(const std::vector<int> &);

#endif
