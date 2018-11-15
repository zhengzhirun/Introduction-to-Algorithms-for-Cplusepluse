/*************************************************************************
	> File Name: gcd_test.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月06日 星期二 22时19分48秒
 ************************************************************************/

#include <iostream>
using std::cout;    using std::endl;
#include "gcd.h"

int main()
{
    int value = gcd(10,2);
    cout << "10和2的最大公因数为: " << value << endl;
    
    unsigned value1 = gcd(1000,89);
    cout << "1000和89的最大公因数为: " << value1 << endl;

    return 0;
}

