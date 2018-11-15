/*************************************************************************
	> File Name: exercise2.23.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月01日 星期四 15时11分36秒
 ************************************************************************/

// 不用递归,写出快速求幂的算法
#include <iostream>
using std::cout;    using std::endl;

double Pow(double x, int n)
{
    double result =1;
    while (n){
        if (n & 1)          // 等价if (n % 2 != 0)
            result *= x;
        n >>= 1;
        x *= x;
    }

    return result;
}

int main()
{
    // 测试算法
    double value = Pow(2,4);
    cout << value << endl;

    return 0;
}

