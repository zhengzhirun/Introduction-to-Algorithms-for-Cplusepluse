/*************************************************************************
	> File Name: minimum_test.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月11日 星期日 11时11分50秒
 ************************************************************************/

#include <iostream>
using std::cout;    using std::endl;
#include <vector>
using std::vector;
#include "minimum.h"
#include <iterator>
using std::begin;   using std::end;

bool compare(int num1, int num2)
{
    return num1 > num2;
}
    
    
template<typename Iterator>
void print(const Iterator begin, const Iterator end)
{
    for (auto current = begin; current != end; ++current)
        cout << *current << " ";
    cout << endl;
}

void Test1()
{
    vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    vector<int> vec1{10,9,8,7,6,5,4,3,2,1};
    vector<int> vec2{1,1,1,1,1,5,5,5,5,5};
    vector<int> vec3{1};

    int min = minimum(vec.begin(), vec.end());
    cout << "序列: ";
    print(vec.begin(), vec.end());
    cout << "的最小值为 " << min << endl;

    min = minimum(vec1.begin(), vec1.end());
    cout << "序列: ";
    print(vec1.begin(), vec1.end());
    cout << "的最小值为 " << min << endl;

    min = minimum(vec2.begin(), vec2.end());
    cout << "序列: ";
    print(vec2.begin(), vec2.end());
    cout << "的最小值为 " << min << endl;

    min = minimum(vec3.begin(), vec3.end());
    cout << "序列: ";
    print(vec3.begin(), vec3.end());
    cout << "的最小值为 " << min << endl;
}

void Test2()
{
    vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    vector<int> vec1{10,9,8,7,6,5,4,3,2,1};
    vector<int> vec2{1,1,1,1,1,5,5,5,5,5};
    vector<int> vec3{1};

    int min = minimum(vec.begin(), vec.end(), compare);
    cout << "序列: ";
    print(vec.begin(), vec.end());
    cout << "的最大值为 " << min << endl;

    min = minimum(vec1.begin(), vec1.end(), compare);
    cout << "序列: ";
    print(vec1.begin(), vec1.end());
    cout << "的最大值为 " << min << endl;

    min = minimum(vec2.begin(), vec2.end(), compare);
    cout << "序列: ";
    print(vec2.begin(), vec2.end());
    cout << "的最大值为 " << min << endl;

    min = minimum(vec3.begin(), vec3.end(), compare);
    cout << "序列: ";
    print(vec3.begin(), vec3.end());
    cout << "的最大值为 " << min << endl;
}

void Test3()
{
    int data1[10] = {1,2,3,4,5,6,7,8,9,10};
    int data2[10] = {10,9,8,7,6,5,4,3,2,1};
    int data3[10] = {1,1,1,1,1,5,5,5,5,5};
    int data4[1] = {1};

    int min = minimum(begin(data1), end(data1));
    cout << "序列: ";
    print(begin(data1), end(data1));
    cout << "的最小值为: " << min << endl;

    min = minimum(begin(data2), end(data2));
    cout << "序列: ";
    print(begin(data2), end(data2));
    cout << "的最小值为: " << min << endl;

    min = minimum(begin(data3), end(data3));
    cout << "序列: ";
    print(begin(data3), end(data3));
    cout << "的最小值为: " << min << endl;

    min = minimum(begin(data4), end(data4));
    cout << "序列: ";
    print(begin(data4), end(data4));
    cout << "的最小值为: " << min << endl;
}

void Test4()
{
    int data1[10] = {1,2,3,4,5,6,7,8,9,10};
    int data2[10] = {10,9,8,7,6,5,4,3,2,1};
    int data3[10] = {1,1,1,1,1,5,5,5,5,5};
    int data4[1] = {1};

    int min = minimum(begin(data1), end(data1), compare);
    cout << "序列: ";
    print(begin(data1), end(data1));
    cout << "的最大值为: " << min << endl;

    min = minimum(begin(data2), end(data2), compare);
    cout << "序列: ";
    print(begin(data2), end(data2));
    cout << "的最大值为: " << min << endl;

    min = minimum(begin(data3), end(data3), compare);
    cout << "序列: ";
    print(begin(data3), end(data3));
    cout << "的最大值为: " << min << endl;

    min = minimum(begin(data4), end(data4), compare);
    cout << "序列: ";
    print(begin(data4), end(data4));
    cout << "的最大值为: " << min << endl;
}


int main()
{
    cout << "***********vector整型数组求最小值**********" << endl;
    Test1();
    cout << "***********vector整型数组求最大值**********" << endl;
    Test2();
    cout << "*************C整型数组求最小值*************" << endl;
    Test3();
    cout << "*************C整型数组求最大值*************" << endl;
    Test4();
        
    return 0;
}

