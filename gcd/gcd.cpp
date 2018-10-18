/*************************************************************************
	> File Name: gcd.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年10月18日 星期四 18时59分00秒
 ************************************************************************/

#include <iostream>

// 欧几里得算法求解最大公因数
long long gcd(long long m, long long n)
{
    // 保证 m > n
    if (m < n){
        long long tem = m;
        m = n;
        n = tem;
    }

    while (n != 0){
        long long rem = m % n;
        m = n;
        n = rem;
    }

    return m;
}

// 测试欧几里得算法求解最大公因数
int main(void)
{
    long long num0, num1;
    std::cout << "请输入两个正整数:\n";
    std::cin >> num0 >> num1;
    long long maxCommonFactor = gcd(num0, num1);
    std::cout << "******************************************************" << std::endl;
    std::cout << "整数" << num0 << "和" << num1 << "的最大公因数为:" 
                << maxCommonFactor << std::endl;

    return 0;
}
