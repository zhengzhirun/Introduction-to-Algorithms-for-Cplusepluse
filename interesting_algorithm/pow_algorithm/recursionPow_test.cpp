/*************************************************************************
	> File Name: recursionPow_test.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月06日 星期二 22时43分19秒
 ************************************************************************/

#include <iostream>
using std::cout;    using std::endl;
#include <cmath>
#include "recursionPow.h"

int main()
{
    double value1 = pow(2.2,2);
    double value3 = pow(2.2222222, 5);
    double value2 = std::pow(2.2,2);
    double value4 = std::pow(2.2222222, 5);
    cout << "递归求幂运算\t数学库求幂\n";
    cout << value1 << "\t" << value2 << endl;
    cout << value3 << "\t" << value4 << endl;

    return 0;
}

