/*************************************************************************
	> File Name: exercise2.17a.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年10月29日 星期一 21时56分50秒
 ************************************************************************/
// 找出最小子序列和

#include <iostream>
using std::cout;    using std::endl;

#include <vector>
using std::vector;

#include <random>
using std::uniform_real_distribution;    using std::default_random_engine;

#include <float.h>
#include <time.h>


// 找出最小子序列和(O(n^2))
double minSubsetAlgorithm1(const vector<double> &vec)
{
    double min = vec[0];
    for (decltype(vec.size()) i = 0; i != vec.size(); ++i){
        double num = 0.0;
        for (decltype(vec.size()) j = i; j != vec.size(); ++j){
            num += vec[j];
            if (num < min)  min = num;
        }
    }
    return min;
}

// 找出三个数中的最小值
double min3(double a, double b, double c)
{
    double min = a;
    if (min > b)
        min = b;
    if (min > c)
        min = c;

    return min;
}

// 找出最小子序列和(O(nlog(n)))(递归分治策略)
double minSubsetAlgorithm2(const vector<double> &vec, int left, int right)
{
    // 基准情形
    if (left == right)
        return vec[left];

    // 递归
    int center = (left + right) / 2;
    double minLeftSum = minSubsetAlgorithm2(vec, left, center);
    double minRightSum = minSubsetAlgorithm2(vec, center + 1, right);

    // 左边的情形
    double minLeftBounderSum = vec[center], leftBounderSum = 0.0;
    for (int i = center; i >= left; --i){
        leftBounderSum += vec[i];
        if (leftBounderSum < minLeftBounderSum)
            minLeftBounderSum = leftBounderSum;
    }

    // 右边的情形
    double minRightBounderSum = vec[center + 1], rightBounderSum = 0.0;
    for (int i = center + 1; i != right; ++i){
        rightBounderSum += vec[i];
        if (rightBounderSum < minRightBounderSum)
            minRightBounderSum = rightBounderSum;
    }

    // 返回最小值
    return min3(minLeftSum, minRightSum, minLeftBounderSum + minRightBounderSum);
}

// 找出最小子序列和(O(N))算法; 联机算法
double minSubsetAlgorithm3(const vector<double> &vec)
{
    double thisSum = 0.0, minSubsetSum = DBL_MAX;
    for (decltype(vec.size()) i = 0; i != vec.size(); ++i){
        thisSum += vec[i];
        if (thisSum < minSubsetSum)
            minSubsetSum = thisSum;
        if (thisSum > minSubsetSum && thisSum > 0)
            thisSum = 0.0;
    }

    return minSubsetSum;
}

// 测试算法
int main()
{
    vector<double> vec;
    // 生成-100~100之前的随机double型数据
    uniform_real_distribution<double> u(-100,100);
    default_random_engine e;
    // 随机生成一个数组
    for (int i = 0; i != 1000; ++i)
        vec.push_back(u(e));
    clock_t start, end;
    // 算法一:算法复杂度为O(n^2)
    start = clock();
    double minSubsetSum = minSubsetAlgorithm1(vec);
    end = clock();
    cout << "******************************minSubsetAlgorithm1****************************************" << endl;
    cout << "double序列的最小子列和为:" << minSubsetSum << ";所耗费的时间为" << (double)(end - start) << endl;
    
    // 算法二:算法复杂度为O(nlog(n))
    start = clock();
    minSubsetSum = minSubsetAlgorithm2(vec, 0, vec.size()-1);
    end = clock();
    cout << "******************************minSubsetAlgorithm2****************************************" << endl;
    cout << "double序列的最小子列和为:" << minSubsetSum << ";所耗费的时间为" << (double)(end - start) << endl;

     // 算法二:算法复杂度为O(nlog(n))
    start = clock();
    minSubsetSum = minSubsetAlgorithm3(vec);
    end = clock();
    cout << "******************************minSubsetAlgorithm2****************************************" << endl;
    cout << "double序列的最小子列和为:" << minSubsetSum << ";所耗费的时间为" << (double)(end - start) << endl;
    
    return 0;
}
