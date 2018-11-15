/*************************************************************************
	> File Name: exercise2.8.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年10月29日 星期一 14时35分27秒
 ************************************************************************/
// 生成前N个整数的一个随机排列.
// 例如,{4,3,1,5,2}和{3,1,4,2,5}就是合法的排列,但{5,4,1,2,1}则不是合法的排列

#include <iostream>
using std::cout;    using std::endl;

#include <random>
using std::uniform_int_distribution;    using std::default_random_engine;

#include <vector>
using std::vector;

#include <utility>
using std::swap;

#include <time.h>

// 生成一个随机排列不重复的数组
void algorithm1(vector<unsigned> &vec, unsigned max)
{
    // 生成1到max之间(包含max)均匀分布的随机数
    uniform_int_distribution<unsigned> u(1,max);
    default_random_engine e;                    // 生成无符号随机整数
    unsigned value = u(e);
    vec.push_back(value);
    for (size_t i = 0; i != max - 1; ++i){
        bool sign;
        do{
            sign = false;
            value = u(e);
            for (auto j : vec)
                if (j == value){ 
                    sign = true;
                    break;
                }
        }while(sign);
        vec.push_back(value);
    }
}

// 生成一个随机排列不重复的数组
void algorithm2(vector<unsigned> &vec, unsigned max)
{
    // 生成1到max之间(包含max)均匀分布的随机数
    uniform_int_distribution<unsigned> u(1,max);
    default_random_engine e;                    // 生成无符号随机整数
    std::vector<bool> used(max,false);          // 存储该数是否用过的信息
    unsigned value = u(e);
    vec.push_back(value);
    used[value] = true;
    for (size_t i = 0; i != max - 1; ++i){
        do{
            value = u(e);
        }while(used[value]);
        vec.push_back(value);
        used[value] = true;
    }
}

// 生成一个随机排列不重复的数组
void algorithm3(std::vector<unsigned> &vec, unsigned max)
{
    // 填写该数组使得vec[i] = i + 1
    for (size_t i = 0; i != max; ++i){
        unsigned value = i + 1;
        vec.push_back(value);
    }
    // 生成0到max之间(包含max)均匀分布的随机数
    uniform_int_distribution<unsigned> u(0,max);
    default_random_engine e;
    for (size_t i = 0; i != max; ++i){
        unsigned index = u(e);
        swap(vec[i], vec[index]);
    }
}

// 测试函数
int main(void)
{
    // 算法一的测试(对max分别取250,500,1000,2000)
    // max的每一个取值计算十次求取平均值
    clock_t start, end;
    unsigned max = 250;
    for (size_t j = 0; j != 4; ++j){
        double time = 0.0;
        for (size_t i = 0; i != 10; ++i){
            vector<unsigned> vec;
            start = clock();
            algorithm1(vec,max);
            end = clock();
            time += (double)(end - start);
        }
        cout << "*********************algorithm1******************************"<<"\n"
            << "max=" << max << ";平均时间:" << time / 10.0 << endl;
        max *= 2;
    }

    // 算法二的测试(对max分别取25 000, 50 000, 100 000, 200 000, 400 000, 800 000)
    max = 250;
    for (size_t i = 0; i != 4; ++i){
        double time = 0.0;
        for (size_t j = 0; j != 10; ++j){
            vector<unsigned> vec;
            start = clock();
            algorithm2(vec, max);
            end = clock();
            time += (double)(end - start);
        }
        cout << "*********************algorithm2******************************"<<"\n"
            << "max=" << max << ";平均时间:" << time / 10.0 << endl;
        max *= 2;
    }

    // 算法三的测试(对N=100 000, 200 000, 400 000, 800 000, 1 600 000, 3 200 000, 6 400 000)
    max = 250;
    for (size_t i = 0; i != 4; ++i){
        double time = 0.0;
        for (size_t j = 0; j != 10; ++j){
            vector<unsigned> vec;
            start = clock();
            algorithm3(vec, max);
            end = clock();
            time += (double)(end - start);
        }
        cout << "*********************algorithm3******************************"<<"\n"
            << "max=" << max << ";平均时间:" << time / 10.0 << endl;
        max *= 2;
    }
    return 0;
}
