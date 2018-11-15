/*************************************************************************
	> File Name: recursionPow.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月06日 星期二 22时28分18秒
 ************************************************************************/

#ifndef _RECURSIONPOW_H
#define _RECURSIONPOW_H
// 递归求幂运算 数据结构与算法分析--C++语言描述 2.4.4
/*
 *\parameter num1: num1^num2;
 *\parameter num2: num1^num2;
 *\return T
 *
 * 算法性能: O(logN)
 * 算法基本思想: 当N是偶数的时候我们有 x^N = x^{N/2} * x^{N/2};
 * 当N是奇数的时候我们有 x^N = x^{(N-1)/2} * x^{(N-1)/2} * x;
 * 根据递归的思想解决.
*/
template<typename T>
T pow(T num1, unsigned long long num2)
{
    // 基准情形
    if (num2 == 1)
        return num1;
    if (num2 == 0)
        return 1;
    // 递归求幂运算
    if (num2 % 2 == 0)
        return pow(num1 * num1, num2 / 2);
    else
        return pow(num1 * num1, num2 / 2) * num1;
}
#endif
