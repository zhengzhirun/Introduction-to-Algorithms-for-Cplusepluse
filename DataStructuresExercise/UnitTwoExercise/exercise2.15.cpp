/*************************************************************************
	> File Name: exercise2.15.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年10月29日 星期一 21时02分17秒
 ************************************************************************/
// 给出一个有效的算法来确定在整数 A_1 < A_2 < A_3 < ... < A_N 的数组是否存在
// 整数i使得A_i = i.

#include <iostream>
using std::cout;    using std::endl;

#include <vector>
using std::vector;

#include <time.h>

int find(const vector<double> &vec, double num)
{
    int begin = 0, end = vec.size() - 1;
    while (begin <= end){
        // 二分策略
        size_t mid = (begin + end) / 2;
        if (vec[mid] > num)
            end = mid - 1;
        else if (vec[mid] < num)
            begin = mid + 1;
        else
            return mid;     // 已找到
    }
    return -1;
}

// 测试程序
int main()
{
    clock_t start, end;
    std::vector<double> vec;
    for (size_t i = 0; i != 10000; ++i)
        vec.push_back(i * 2.8 + 1.89);
    start = clock();
    int index = find(vec, 281.89);
    end = clock();
    cout << "281.89在向量中的第" << index << "个;\t所耗费的时间为:" << (double)(end - start) << endl;
    return 0;
}


