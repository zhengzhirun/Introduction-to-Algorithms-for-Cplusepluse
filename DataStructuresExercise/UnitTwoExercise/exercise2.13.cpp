/*************************************************************************
	> File Name: exercise2.13.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年10月29日 星期一 19时41分28秒
 ************************************************************************/
// 计算f(x) = \sum_{i = 0}^{n} a_i*x^i

#include <iostream>
using std::cout;    using std::endl;

#include <vector>
using std::vector;

#include <time.h>

// 简单的执行取幂的运算
double algorithm1(const vector<double> &a, double x)
{
    double solution = 0.0;
    for (size_t i = 0; i != a.size(); ++i){
        double pow = 1.0;
        for (size_t j = 0; j != i; ++j)
            pow *= x; 
        solution += pow * a[i];
    }

    return solution;
}

// 高效幂运算
double pow(double x, int n)
{
    // 基准情形
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    if (n % 2 == 0) // n为偶数的情况
        return pow(x * x, n / 2);
    else            // n为奇数的情况
        return pow(x * x, n / 2) * x;
}

double algorithm2(const vector<double> &a, double x)
{
    double solution = 0.0;
    for (size_t i = 0; i != a.size(); ++i)
        solution += a[i] * pow(x,i);
    return solution;
}

// 练习2.14提出的Horner法则
double Horner(const vector<double> &a, double x)
{
    double solution = 0.0;
    for (int i = a.size() - 1; i >= 0; --i)
        solution = x * solution + a[i];
    return solution;
}

// 测试函数
int main()
{
    vector<double> a{2,1,0,8,4};
    clock_t start, end;
    double x = 21.0;
    // 测试算法1
    cout << "******************algorithm1********************************" << endl;
    start = clock();
    double solution = algorithm1(a,x);
    end = clock();
    cout << "当x的值为" << x << "时多项式的解为" << solution <<"\t运行时间为"<< (double)(end - start) << endl;
    // 测试算法2
    cout << "******************algorithm2********************************" << endl;
    start = clock();
    solution = algorithm2(a,x);
    end = clock();
    cout << "当x的值为" << x << "时多项式的解为" << solution <<"\t运行时间为"<< (double)(end - start) << endl;
    // 测试算法3
    cout << "*****************Horner*************************************" << endl;
    start = clock();
    solution = Horner(a,x);
    end = clock();
    cout << "当x的值为" << x << "时多项式的解为" << solution << "\t运行时间为" << (double)(end - start) << endl;

    return 0;
}
