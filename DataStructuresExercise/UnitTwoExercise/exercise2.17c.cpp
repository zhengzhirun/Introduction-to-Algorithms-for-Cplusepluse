/*************************************************************************
	> File Name: exercise2.17c.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年10月31日 星期三 09时27分40秒
 ************************************************************************/

// 找出最大子序列乘积

#include <iostream>
using std::cout;    using std::endl;

#include <vector>
using std::vector;

#include <random>
using std::uniform_real_distribution;   using std::default_random_engine;

#include <float.h>
#include <time.h>

// 找出最大子序列乘积(O(n^2))
double maxSubsetProduct1(const vector<double> &vec)
{
    double maxSubset = DBL_MIN;
    for (decltype(vec.size()) i = 0; i != vec.size(); ++i){
        double thisMaxSubset = 1.0;
        for (decltype(vec.size()) j = i; j != vec.size(); ++j){
            thisMaxSubset *= vec[j];
            if (thisMaxSubset > maxSubset)
                maxSubset = thisMaxSubset;
        }
    }

    return maxSubset;
}

// 最大子序列乘积的联机算法(O(n))
double maxSubsetProduct2(vector<double> &vec)
{
    double maxSubset = DBL_MIN;
    double thisMax = 0.0, thisMin = 0.0;

    for (decltype(vec.size()) i = 0; i != vec.size(); ++i){
        if (vec[i] > 0){
            thisMax = thisMax ? vec[i] * thisMax : vec[i];
            thisMin = thisMin ? vec[i] * thisMin : vec[i];

            thisMax = (thisMax < vec[i]) ? vec[i] : thisMax;
        }
        else if (vec[i] < 0){
            double temp = thisMax;
            thisMax = thisMin ? vec[i] * thisMin : 0.0;
            thisMin = temp ? vec[i] * temp : vec[i]; 

            thisMin = (thisMin > vec[i]) ? vec[i] : thisMin;
        }
        else{
            thisMax = 0.0;
            thisMin = 0.0;
        }
        maxSubset = (maxSubset > thisMax) ? maxSubset : thisMax;   
    }

    return maxSubset;
}



// 测试
int main()
{
    vector<double> vec;
    // 生成-100到100之间的随机double型数据
    uniform_real_distribution<double> u(-2,2);
    default_random_engine e;
    // 随机生成一个数组
    for (int i = 0; i != 1000; ++i)
        vec.push_back(u(e));
    clock_t start, end;
    // 算法一的测试
    start = clock();
    double value = maxSubsetProduct1(vec);
    end = clock();
    cout << "*******************************maxSubsetProduct1***********************************\n"
        << "随机序列中的最大乘积为:" << value << ";所耗费的时间为:" << (double)(end - start) << endl;
    
    // 算法二的测试
    start = clock();
    value = maxSubsetProduct2(vec);
    end = clock();
    cout << "*******************************maxSubsetProduct2***********************************\n"
        << "随机序列中的最大乘积为:" << value << ";所耗费的时间为:" << (double)(end - start) << endl;

    return 0;
}
