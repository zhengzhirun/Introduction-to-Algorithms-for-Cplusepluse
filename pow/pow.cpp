/*************************************************************************
	> File Name: pow.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年10月18日 星期四 19时13分31秒
 ************************************************************************/

#include <iostream>

// 幂运算的递归算法
long long pow(long long x, int n)
{
    // 基准情况
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    if (n % 2 == 0)         // n为偶数的情况
        return pow(x * x, n / 2);
    else
        return pow(x * x, n / 2) * x;       // n为奇数的情况
}

int main(void)
{
    std::cout << "输入两个整数:" << std::endl;
    long long x;
    int n;
    std::cin >> x >> n;
    long long value = pow(x, n);
    std::cout << x << "的" << n << "次方为: " << value << std::endl;

    return 0;
}
