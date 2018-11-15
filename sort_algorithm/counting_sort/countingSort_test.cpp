/*************************************************************************
	> File Name: countingSort_test.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月09日 星期五 11时12分38秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <iostream>
using std::cout;    using std::endl;
#include <iterator>
using std::begin;   using std::end;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;
#include "countingSort.h"

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
    int data1[10] = {1,2,3,4,5,6,7,8,9,10};
    int data2[10] = {10,9,8,7,6,5,4,3,2,1};
    int data3[10] = {1,1,1,1,1,5,5,5,5,5};
    int data4[1] = {2};
    int compareData1[10] = {1,2,3,4,5,6,7,8,9,10};
    int compareData2[10] = {10,9,8,7,6,5,4,3,2,1};
    int compareData3[10] = {1,1,1,1,1,5,5,5,5,5};
    int compareData4[1] = {2};

    countingSort(begin(data1), end(data1),10);
    sort(begin(compareData1), end(compareData1));
    
    countingSort(begin(data2), end(data2),10);
    sort(begin(compareData2), end(compareData2));

    countingSort(begin(data3), end(data3),5);
    sort(begin(compareData3), end(compareData3));
    
    countingSort(begin(data4), end(data4),2);
    sort(begin(compareData4), end(compareData4));

    // 输出排序后的数组
    cout << "****************对升序数组进行测试*********************\n";
    cout << "countingSort排序结果:\n";
    print(begin(data1), end(data1));
    cout << "sort排序结果:\n";
    print(begin(compareData1), end(compareData1));
    
    cout << "****************对降序数组进行测试*********************\n";
    cout << "countingSort排序结果:\n";
    print(begin(data2), end(data2));
    cout << "函数库sort排序结果:\n";
    print(begin(compareData2), end(compareData2));

    cout << "****************对有重复数字进行测试*******************\n";
    cout << "countingSort排序结果:\n";
    print(begin(data3), end(data3));
    cout << "函数库sort排序结果:\n";
    print(begin(compareData3), end(compareData3));

    cout << "****************单个数组元素的测试*********************\n";
    cout << "countingSort排序结果:\n";
    print(begin(data4), end(data4));
    cout << "函数库sort排序结果:\n";
    print(begin(compareData4), end(compareData4));
}

void Test2()
{
    cout << "***********测试计数排序算法只使用于整数排序************\n";
    double data1[10] = {2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3.0};
    double compareData1[10] = {2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3.0};

    // 这句话在编译的时候就不会通过,因为不能通过static_assert断言测试.
    //countingSort(begin(data1), end(data1), 3); 
    sort(begin(compareData1), end(compareData1));
    // 输出排序后的数组
    cout << "函数库sort排序的结果:\n";
    print(begin(compareData1), end(compareData1));
}

void Test3()
{
    vector<int> data1 = {1,2,3,4,5,6,7,8,9,10};
    vector<int> data2 = {10,9,8,7,6,5,4,3,2,1};
    vector<int> data3 = {1,1,1,1,1,5,5,5,5,5};
    vector<int> data4 = {2};

    vector<int> compareData1(data1.begin(), data1.end());
    vector<int> compareData2(data2.begin(), data2.end());
    vector<int> compareData3(data3.begin(), data3.end());
    vector<int> compareData4(data4.begin(), data4.end());

    countingSort(data1.begin(), data1.end(), 10);
    sort(compareData1.begin(), compareData1.end());

    countingSort(data2.begin(), data2.end(), 10);
    sort(compareData2.begin(), compareData2.end());

    countingSort(data3.begin(), data3.end(), 5);
    sort(compareData3.begin(), compareData3.end());

    countingSort(data4.begin(), data4.end(), 2);
    sort(compareData4.begin(), compareData4.end());

    // 输出排序结果
    cout << "****************对升序数组进行测试*********************\n";
    cout << "countingSort排序结果:\n";
    print(data1.begin(), data1.end());
    cout << "函数库sort排序结果:\n";
    print(compareData1.begin(), compareData1.end());

    cout << "****************对降序数组进行测试*********************\n";
    cout << "countingSort排序结果:\n";
    print(data2.begin(), data2.end());
    cout << "函数库sort排序结果:\n";
    print(compareData2.begin(), compareData2.end());

    cout << "****************对有重复数字进行测试*******************\n";
    cout << "countingSort排序结果:\n";
    print(data3.begin(), data3.end());
    cout << "函数库sort排序结果:\n";
    print(compareData3.begin(), compareData3.end());
    
    cout << "****************单个数组元素的测试*********************\n";
    cout << "countingSort排序结果:\n";
    print(data4.begin(), data4.end());
    cout << "函数库sort排序结果:\n";
    print(compareData4.begin(), compareData4.end()); 
}

int main()
{
    cout << "******************对C数组升序排列测试******************\n";
    Test1();
    cout << "***************测试计数排序只能用于整数排序************\n";
    Test2();
    
    cout << "******************对vector数组升序排列测试*************\n";
    Test3();

    return 0;
}
