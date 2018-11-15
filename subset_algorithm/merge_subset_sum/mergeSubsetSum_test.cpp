/*************************************************************************
	> File Name: mergeSubSetSum_test.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月06日 星期二 20时32分06秒
 ************************************************************************/

#include <iostream>
using std::cout;    using std::endl;
#include <vector>
using std::vector;
#include <array>
using std::array;
#include "mergeSubsetSum.h"

bool compare(int num1, int num2)
{
    return num1 > num2;
}

void Test1()
{
    vector<int> vec1{1,2,3,4,5,6,7,8,9,10};
    vector<int> vec2{1,-2,3,-4,5,-6,7,-8,9,-10};
    vector<int> vec4{-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
    cout << "*********************递归算法的测试*************************\n";
    int max = megre(vec1.cbegin(), vec1.cend());
    int min = megre(vec1.cbegin(), vec1.cend(), compare);
    cout << "********************全部都是正数的数组**********************\n";
    // 输出数组
    for (auto i : vec1)
        cout << i << " ";
    cout << endl;
    cout <<"最大相连子序列和:\t" << max <<"\n"
        << "最小相连子序列和:\t" << min << endl;
    max = megre(vec2.cbegin(), vec2.cend());
    min = megre(vec2.cbegin(), vec2.cend(),compare);
    cout << "********************有正数有负数的数组**********************\n";
    for (auto i : vec2)
        cout << i << " ";
    cout << endl;
    cout << "最大相连子序列和:\t" << max << "\n"
        << "最小相连子序列和:\t" << min << endl;
    cout << "*********************全部都是负数的数组*********************\n";
    for (auto i : vec4)
        cout << i << " ";
    cout << endl;
    max = megre(vec4.cbegin(), vec4.cend());
    min = megre(vec4.cbegin(), vec4.cend(),compare);
    cout << "最大相连子序列和:\t" << max << "\n"
        << "最小相连子序列和:\t" << min << endl;
}

int main()
{
    Test1();

    return 0;
}
