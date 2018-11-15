/*************************************************************************
	> File Name: exercise2.21.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月01日 星期四 11时05分20秒
 ************************************************************************/

// 计算小于N的所有素数的方法
#include <iostream>
using std::cout;    using std::endl;

#include <cmath>
using std::sqrt;

#include <vector>
using std::vector;

#include <time.h>

bool isPrimer1(long long unsigned num)
{
    bool sign = true;
    if (num <= 25){
        for (long long unsigned i = 2; i <= sqrt(num); ++i)
            if (num % i == 0){
                sign = false;
                break;
            }   
    }
    else{
        if (num % 6 != 1 && num % 6 != 5)
            sign = false;
        else
            for (long long unsigned i = 5; i <= sqrt(num); i+=6)
                if (num % i == 0 || num % (i+2) == 0){
                    sign = false;
                    break;
                }
    }

    return sign;
}

bool isPrimer2(long long unsigned num)
{
    bool sign = true;
    for (long long unsigned i = 2; i <= sqrt(num); ++i)
        if (num % i == 0){
            sign = false;
            break;
        }

    return sign;
}

// 输出小于正整数N的所有素数 算法1
void findPrimer1(vector<long long unsigned> &vec, long long unsigned maxNum)
{
    for (long long unsigned i = 2; i != maxNum; ++i){
        if (isPrimer1(i))
            vec.push_back(i);
    }
}

// 输出小于正整数N的所有素数 算法二
void findPrimer2(vector<long long unsigned> &vec, long long unsigned maxNum)
{
    for (long long unsigned i = 2; i != maxNum; ++i){
        if (isPrimer2(i))
            vec.push_back(i);
    }
}

// 输出小于正整数N的所有素数 算法三(厄拉多塞筛)
void findPrimer3(vector<long long unsigned> &vec, vector<bool> &index, long long unsigned maxNum)
{
    // 初始化vec
    for (long long unsigned i = 0; i <= maxNum; ++i){
        vec.push_back(i);
        index.push_back(true);
    }
    // 找出最小的素数然后修改下标矩阵
    for (decltype(vec.size()) i = 2; i <= sqrt(vec.size()); ++i){
        if (isPrimer1(vec[i]) && index[i])
            for (auto j = i + i; j <= vec.size(); j += i)
                index[j] = false;
    }
}

int main()
{
    long long unsigned maxNum = 10000001;
    vector<long long unsigned> vecNum1, vecNum2;
    clock_t start, end;
    // 算法一的测试
    start = clock();
    findPrimer1(vecNum1, maxNum);
    end = clock();
    cout << "算法1所花非的时间为: " << (double)(end-start) << endl;

    // 算法二的测试
    start = clock();
    findPrimer2(vecNum2, maxNum);
    end = clock();
    cout << "算法2所花费的时间为: " << (double)(end-start) << endl;

    // 算法三的测试
    vector<long long unsigned> vec;
    vector<bool> index;
    start = clock();
    findPrimer3(vec, index, maxNum);
    end = clock();
    cout << "算法3所花费的时间为: " << (double)(end - start) << endl;
 
    return 0;
}
