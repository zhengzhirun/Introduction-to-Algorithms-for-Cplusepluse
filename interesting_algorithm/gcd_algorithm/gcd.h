/*************************************************************************
	> File Name: gcd.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月06日 星期二 22时06分38秒
 ************************************************************************/

#ifndef _GCD_H
#define _GCD_H
// 欧几里得算法求解最大公因数 数据结构与算法分析--C++语言描述 2.4.4
/*
 * \parameter num1: 求解最大公因数的参数1;
 * \parameter num2: 求解最大公因数的参数2;
 * \return T;
 *
 * 算法性能 O(logN);
 * 算法具体思想: 辗转相除法.
*/
template<typename T>
T gcd(T num1, T num2)
{
    if (num1 < num2){
        T temp = num1;
        num1 = num2;
        num2 = temp;
    }
    // 辗转相除策略
    while (num2 > 0){
        T rem = num1 % num2;
        num1 = num2;
        num2 = rem;
    }

    return num1;
}

#endif
