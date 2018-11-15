/*************************************************************************
	> File Name: radixSort_test.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月10日 星期六 17时16分38秒
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
#include "radixSort.h"

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
    int data1[10] = {101, 111, 121, 131, 141, 151, 161, 171, 181, 191};
    int data2[10] = {191, 181, 171, 161, 151, 141, 131, 121, 111, 101};
    int data3[10] = {111, 111, 111, 111, 111, 555, 555, 555, 555, 555};
    int data4[1] = {222};
    int data5[7] = {329, 457, 657, 839, 436, 720, 355};

    int compareData1[10] = {101, 111, 121, 131, 141, 151, 161, 171, 181, 191};
    int compareData2[10] = {191, 181, 171, 161, 151, 141, 131, 121, 111, 101};
    int compareData3[10] = {111, 111, 111, 111, 111, 555, 555, 555, 555, 555};
    int compareData4[1] = {222};
    int compareData5[7] = {329, 457, 657, 839, 436, 720, 355};

    radixSort(begin(data1), end(data1),3);
    sort(begin(compareData1), end(compareData1));
    
    radixSort(begin(data2), end(data2),3);
    sort(begin(compareData2), end(compareData2));

    radixSort(begin(data3), end(data3),3);
    sort(begin(compareData3), end(compareData3));
    
    radixSort(begin(data4), end(data4),3);
    sort(begin(compareData4), end(compareData4));

    radixSort(begin(data5), end(data5), 3);
    sort(begin(compareData5), end(compareData5));

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

    cout << "****************凌乱数组元素的测试**********************\n";
    cout << "countingSort排序结果:\n";
    print(begin(data5), end(data5));
    cout << "函数库sort排序结果:\n";
    print(begin(compareData5), end(compareData5));
}

void Test2()
{
    cout << "***********测试计数排序算法只使用于整数排序************\n";
    double data1[10] = {101, 111, 121, 131, 141, 151, 161, 171, 181, 191};
    double compareData1[10] = {101, 111, 121, 131, 141, 151, 161, 171, 181, 191};

    // 这句话在编译的时候就不会通过,因为不能通过static_assert断言测试.
    //countingSort(begin(data1), end(data1), 3); 
    sort(begin(compareData1), end(compareData1));
    // 输出排序后的数组
    cout << "函数库sort排序的结果:\n";
    print(begin(compareData1), end(compareData1));
}

void Test3()
{
    vector<int> data1 = {101, 111, 121, 131, 141, 151, 161, 171, 181, 191};
    vector<int> data2 = {191, 181, 171, 161, 151, 141, 131, 121, 111, 101};
    vector<int> data3 = {111, 111, 111, 111, 111, 555, 555, 555, 555, 555};
    vector<int> data4 = {222};
    vector<int> data5 = {329, 457, 657, 839, 436, 720, 355};

    vector<int> compareData1(data1.begin(), data1.end());
    vector<int> compareData2(data2.begin(), data2.end());
    vector<int> compareData3(data3.begin(), data3.end());
    vector<int> compareData4(data4.begin(), data4.end());
    vector<int> compareData5(data5.begin(), data5.end());

    radixSort(data1.begin(), data1.end(), 3);
    sort(compareData1.begin(), compareData1.end());

    radixSort(data2.begin(), data2.end(), 3);
    sort(compareData2.begin(), compareData2.end());

    radixSort(data3.begin(), data3.end(), 3);
    sort(compareData3.begin(), compareData3.end());

    radixSort(data4.begin(), data4.end(), 3);
    sort(compareData4.begin(), compareData4.end());

    radixSort(data5.begin(), data5.end(), 3);
    sort(compareData5.begin(), compareData5.end());

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

    cout << "****************对凌乱数组元素的测试*******************\n";
    cout << "countingSort排序结果:\n";
    print(data5.begin(), data5.end());
    cout << "函数库sort排序结果:\n";
    print(compareData5.begin(), compareData5.end());
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
