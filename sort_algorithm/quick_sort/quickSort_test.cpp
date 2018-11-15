/*************************************************************************
	> File Name: quickSort_test.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月08日 星期四 21时44分25秒
 ************************************************************************/
#include <iostream>
using std::cout;    using std::endl;
#include <iterator>
using std::begin;   using std::end;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;
#include "quickSort.h"

// 数组输出函数
template<typename Iterator>
void print(const Iterator begin, const Iterator end)
{
    for (auto current = begin; current != end; ++current)
        cout << *current << " ";
    cout << endl;
}
// 降序
bool compareInt(int num1, int num2)
{
    return num1 >  num2;
}

bool compareDouble(double num1, double num2)
{
    return num1 > num2;
}

void Test1()
{
    int data1[10] = {1,2,3,4,5,6,7,8,9,10};
    int data2[10] = {10,9,8,7,6,5,4,3,2,1};
    int data3[10] = {1,1,1,1,1,5,5,5,5,5};
    int data4[1] = {2};
    int compareData1[10] = {1,2,3,4,5,6,7,8,9,10};
    int compareData2[10] = {10,9,8,7,6,5,4,3,2,1};
    int compareData3[10] = {1,1,1,1,1,5,5,5,5,5};
    int compareData4[1] = {2};

    quickSort(begin(data1), end(data1));
    sort(begin(compareData1), end(compareData1));
    
    quickSort(begin(data2), end(data2));
    sort(begin(compareData2), end(compareData2));

    quickSort(begin(data3), end(data3));
    sort(begin(compareData3), end(compareData3));
    
    quickSort(begin(data4), end(data4));
    sort(begin(compareData4), end(compareData4));

    // 输出排序后的数组
    cout << "****************对升序数组进行测试*********************\n";
    cout << "insertSort排序结果:\n";
    print(begin(data1), end(data1));
    cout << "sort排序结果:\n";
    print(begin(compareData1), end(compareData1));
    
    cout << "****************对降序数组进行测试*********************\n";
    cout << "insertSort排序结果:\n";
    print(begin(data2), end(data2));
    cout << "函数库sort排序结果:\n";
    print(begin(compareData2), end(compareData2));

    cout << "****************对有重复数字进行测试*******************\n";
    cout << "insertSort排序结果:\n";
    print(begin(data3), end(data3));
    cout << "函数库sort排序结果:\n";
    print(begin(compareData3), end(compareData3));

    cout << "****************单个数组元素的测试*********************\n";
    cout << "insertSort排序结果:\n";
    print(begin(data4), end(data4));
    cout << "函数库sort排序结果:\n";
    print(begin(compareData4), end(compareData4));
}

void Test2()
{
    vector<double> data1{1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0};
    vector<double> compareData1(data1.begin(), data1.end());
    vector<double> data2{2.0,1.9,1.8,1.7,1.6,1.5,1.4,1.3,1.2,1.1};
    vector<double> compareData2(data2.begin(), data2.end());
    vector<double> data3{1.1,1.1,1.1,1.1,1.1,2.2,2.2,2.2,2.2,2.2};
    vector<double> compareData3(data3.begin(), data3.end());
    vector<double> data4{1.1};
    vector<double> compareData4{1.1};

    quickSort(data1.begin(), data1.end());
    sort(compareData1.begin(), compareData1.end());
    
    quickSort(data2.begin(), data2.end());
    sort(compareData2.begin(), compareData2.end());

    quickSort(data3.begin(), data3.end());
    sort(compareData3.begin(), compareData3.end());

    quickSort(data4.begin(), data4.end());
    sort(compareData4.begin(), compareData4.end());

    cout << "****************对升序数组进行测试*********************\n";
    cout << "insertSort排序结果:\n";
    print(data1.begin(), data1.end());
    cout << "函数库sort排序结果:\n";
    print(compareData1.begin(), compareData1.end());

    cout << "****************对降序数组进行测试*********************\n";
    cout << "insertSort排序结果:\n";
    print(data2.begin(), data2.end());
    cout << "函数库sort排序结果:\n";
    print(compareData2.begin(), compareData2.end());

    cout << "****************对有重复数字进行测试*******************\n";
    cout << "insertSort排序结果:\n";
    print(data3.begin(), data3.end());
    cout << "函数库sort排序结果:\n";
    print(compareData3.begin(), compareData3.end());

    cout << "****************对单个数字进行测试*********************\n";
    cout << "insertSort排序结果\n";
    print(data4.begin(), data4.end());
    cout << "函数库sort排序结果:\n";
    print(compareData4.begin(), compareData4.end());
}

void Test3()
{
    int data1[10] = {1,2,3,4,5,6,7,8,9,10};
    int data2[10] = {10,9,8,7,6,5,4,3,2,1};
    int data3[10] = {1,1,1,1,1,5,5,5,5,5};
    int data4[1] = {2};
    int compareData1[10] = {1,2,3,4,5,6,7,8,9,10};
    int compareData2[10] = {10,9,8,7,6,5,4,3,2,1};
    int compareData3[10] = {1,1,1,1,1,5,5,5,5,5};
    int compareData4[1] = {2};

    quickSort(begin(data1), end(data1), compareInt);
    sort(begin(compareData1), end(compareData1), compareInt);
    
    quickSort(begin(data2), end(data2), compareInt);
    sort(begin(compareData2), end(compareData2), compareInt);

    quickSort(begin(data3), end(data3), compareInt);
    sort(begin(compareData3), end(compareData3), compareInt);
   
    quickSort(begin(data4), end(data4), compareInt);
    sort(begin(compareData4), end(compareData4), compareInt);

    // 输出排序后的数组
    cout << "****************对升序数组进行测试*********************\n";
    cout << "insertSort排序结果:\n";
    print(begin(data1), end(data1));
    cout << "sort排序结果:\n";
    print(begin(compareData1), end(compareData1));
    
    cout << "****************对降序数组进行测试*********************\n";
    cout << "insertSort排序结果:\n";
    print(begin(data2), end(data2));
    cout << "函数库sort排序结果:\n";
    print(begin(compareData2), end(compareData2));

    cout << "****************对有重复数字进行测试*******************\n";
    cout << "insertSort排序结果:\n";
    print(begin(data3), end(data3));
    cout << "函数库sort排序结果:\n";
    print(begin(compareData3), end(compareData3));

    cout << "****************单个数组元素的测试*********************\n";
    cout << "insertSort排序结果:\n";
    print(begin(data4), end(data4));
    cout << "函数库sort排序结果:\n";
    print(begin(compareData4), end(compareData4));
}

void Test4()
{
    vector<double> data1{1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0};
    vector<double> compareData1(data1.begin(), data1.end());
    vector<double> data2{2.0,1.9,1.8,1.7,1.6,1.5,1.4,1.3,1.2,1.1};
    vector<double> compareData2(data2.begin(), data2.end());
    vector<double> data3{1.1,1.1,1.1,1.1,1.1,2.2,2.2,2.2,2.2,2.2};
    vector<double> compareData3(data3.begin(), data3.end());
    vector<double> data4{1.1};
    vector<double> compareData4{1.1};

    quickSort(data1.begin(), data1.end(), compareDouble);
    sort(compareData1.begin(), compareData1.end(), compareDouble);
    
    quickSort(data2.begin(), data2.end(), compareDouble);
    sort(compareData2.begin(), compareData2.end(), compareDouble);

    quickSort(data3.begin(), data3.end(), compareDouble);
    sort(compareData3.begin(), compareData3.end(), compareDouble);

    quickSort(data4.begin(), data4.end(), compareDouble);
    sort(compareData4.begin(), compareData4.end(), compareDouble);

    cout << "****************对升序数组进行测试*********************\n";
    cout << "insertSort排序结果:\n";
    print(data1.begin(), data1.end());
    cout << "函数库sort排序结果:\n";
    print(compareData1.begin(), compareData1.end());

    cout << "****************对降序数组进行测试*********************\n";
    cout << "insertSort排序结果:\n";
    print(data2.begin(), data2.end());
    cout << "函数库sort排序结果:\n";
    print(compareData2.begin(), compareData2.end());

    cout << "****************对有重复数字进行测试*******************\n";
    cout << "insertSort排序结果:\n";
    print(data3.begin(), data3.end());
    cout << "函数库sort排序结果:\n";
    print(compareData3.begin(), compareData3.end());

    cout << "****************对单个数字进行测试*********************\n";
    cout << "insertSort排序结果\n";
    print(data4.begin(), data4.end());
    cout << "函数库sort排序结果:\n";
    print(compareData4.begin(), compareData4.end());
}

int main()
{
    cout << "****************对C数组升序排列测试********************\n";
    Test1();

    cout << "****************对vector数组升序排列测试***************\n";
    Test2();

    cout << "****************对C数组降序排列测试********************\n";
    Test3();
    
    cout << "****************对vector数组降序排列测试***************\n";
    Test4();
    
    return 0;
}
