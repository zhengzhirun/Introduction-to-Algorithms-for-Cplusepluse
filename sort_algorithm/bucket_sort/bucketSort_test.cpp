/*************************************************************************
	> File Name: bucketSort_test.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月10日 星期六 21时57分35秒
 ************************************************************************/
#include <iostream>
using std::cout;    using std::endl;
#include <iterator>
using std::begin;   using std::end;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;
#include "bucketSort.h"

// 数组输出函数
template<typename Iterator>
void print(const Iterator begin, const Iterator end)
{
    for (auto current = begin; current != end; ++current)
        cout << *current << " ";
    cout << endl;
}

void Test1()
{
    double data1[10] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 0.99};
    double data2[10] = {0.99, 0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1};
    double data3[10] = {0.1, 0.1, 0.1, 0.1, 0.1, 0.5, 0.5, 0.5, 0.5, 0.5};
    double data4[1] = {0.2};
    double data5[10] = {0.32, 0.45, 0.33, 0.456, 0.342, 0.456, 0.87, 0.78, 0.98, 0.99};

    double compareData1[10] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9,0.99};
    double compareData2[10] = {0.99, 0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1};
    double compareData3[10] = {0.1, 0.1, 0.1, 0.1, 0.1, 0.5, 0.5, 0.5, 0.5, 0.5};
    double compareData4[1] = {0.2};
    double compareData5[10] = {0.32, 0.45, 0.33, 0.456, 0.342, 0.456, 0.87, 0.78, 0.98, 0.99};

    bucketSort(begin(data1), end(data1),0, 1);
    sort(begin(compareData1), end(compareData1));
    
    bucketSort(begin(data2), end(data2),0, 1);
    sort(begin(compareData2), end(compareData2));

    bucketSort(begin(data3), end(data3),0, 1);
    sort(begin(compareData3), end(compareData3));
    
    bucketSort(begin(data4), end(data4),0, 1);
    sort(begin(compareData4), end(compareData4));

    bucketSort(begin(data5), end(data5),0, 1);
    sort(begin(compareData5), end(compareData5));

    // 输出排序后的数组
    cout << "****************对升序数组进行测试*********************\n";
    cout << "bucketSort排序结果:\n";
    print(begin(data1), end(data1));
    cout << "sort排序结果:\n";
    print(begin(compareData1), end(compareData1));
    
    cout << "****************对降序数组进行测试*********************\n";
    cout << "bucketSort排序结果:\n";
    print(begin(data2), end(data2));
    cout << "函数库sort排序结果:\n";
    print(begin(compareData2), end(compareData2));

    cout << "****************对有重复数字进行测试*******************\n";
    cout << "bucketSort排序结果:\n";
    print(begin(data3), end(data3));
    cout << "函数库sort排序结果:\n";
    print(begin(compareData3), end(compareData3));

    cout << "****************单个数组元素的测试*********************\n";
    cout << "bucketSort排序结果:\n";
    print(begin(data4), end(data4));
    cout << "函数库sort排序结果:\n";
    print(begin(compareData4), end(compareData4));

    cout << "****************混乱数组元素的测试*********************\n";
    cout << "bucketSort排序结果:\n";
    print(begin(data5), end(data5));
    cout << "函数库sort排序结果:\n";
    print(begin(compareData5), end(compareData5));
}

void Test2()
{
    vector<double> data1{0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 0.99};
    vector<double> compareData1(data1.begin(), data1.end());
    vector<double> data2{0.99, 0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1};
    vector<double> compareData2(data2.begin(), data2.end());
    vector<double> data3{0.1, 0.1, 0.1, 0.1, 0.1, 0.5, 0.5, 0.5, 0.5, 0.5};
    vector<double> compareData3(data3.begin(), data3.end());
    vector<double> data4{0.5};
    vector<double> compareData4{0.5};
    vector<double> data5{0.32, 0.45, 0.33, 0.456, 0.342, 0.456, 0.87, 0.78, 0.98, 0.99};
    vector<double> compareData5(data5.begin(), data5.end());

    bucketSort(data1.begin(), data1.end(), 0, 1);
    sort(compareData1.begin(), compareData1.end());
    
    bucketSort(data2.begin(), data2.end(), 0, 1);
    sort(compareData2.begin(), compareData2.end());

    bucketSort(data3.begin(), data3.end(), 0, 1);
    sort(compareData3.begin(), compareData3.end());

    bucketSort(data4.begin(), data4.end(), 0, 1);
    sort(compareData4.begin(), compareData4.end());

    bucketSort(data5.begin(), data5.end(), 0, 1);
    sort(compareData5.begin(), compareData5.end());

    cout << "****************对升序数组进行测试*********************\n";
    cout << "bucketSort排序结果:\n";
    print(data1.begin(), data1.end());
    cout << "函数库sort排序结果:\n";
    print(compareData1.begin(), compareData1.end());

    cout << "****************对降序数组进行测试*********************\n";
    cout << "bucketSort排序结果:\n";
    print(data2.begin(), data2.end());
    cout << "函数库sort排序结果:\n";
    print(compareData2.begin(), compareData2.end());

    cout << "****************对有重复数字进行测试*******************\n";
    cout << "bucketSort排序结果:\n";
    print(data3.begin(), data3.end());
    cout << "函数库sort排序结果:\n";
    print(compareData3.begin(), compareData3.end());

    cout << "****************对单个数字进行测试*********************\n";
    cout << "bucketSort排序结果\n";
    print(data4.begin(), data4.end());
    cout << "函数库sort排序结果:\n";
    print(compareData4.begin(), compareData4.end());

    cout << "****************对混乱数据进行测试*********************\n";
    cout << "bucketSort排序结果:\n";
    print(data5.begin(), data5.end());
    cout << "函数库sort排序结果:\n";
    print(compareData5.begin(), compareData5.end());

}

int main()
{
    
    cout << "****************对C数组升序排列测试********************\n";
    Test1();

    cout << "****************对vector数组升序排列测试***************\n";
    Test2();

    return 0;
}
