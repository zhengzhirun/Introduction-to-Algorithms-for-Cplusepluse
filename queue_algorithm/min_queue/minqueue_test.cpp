/*************************************************************************
	> File Name: minqueue_test.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月08日 星期四 11时24分22秒
 ************************************************************************/

#include <iostream>
using std::cout;    using std::endl;
#include "minqueue.h"
// 当最小优先队列存放的是int*数据时,相应的比较函数对象
typedef std::function<bool (std::shared_ptr<int>, std::shared_ptr<int>)> IntCompareType;
// 当最小优先级队列存放的是int*数据时,获取key的函数对象
typedef std::function<int& (std::shared_ptr<int>)> IntGetType;
// 存放的是int*数据的最小优先级队列,其关键字就是int本身
typedef MinQueue<int, int> IntMinqueueType;

IntCompareType intCompare=[](std::shared_ptr<int> first, std::shared_ptr<int> second) {return (*first < *second);};
IntGetType intGetType=[](std::shared_ptr<int> node)->int& {return *node;};

// 测试最小优先队列的成员函数insert()
void insertTest()
{
    cout << "*************Minqueue成员函数insert的测试:************************\n";
    cout << "********int型数据的测试:***************\n";
    IntMinqueueType minQueue(10, intCompare, intGetType);
    cout << "依次插入1,2,3,4,5,6,7,8,9,10返回元素插入的位置:\n";
    for (int i = 1; i <= 10; ++i){
        int index = minQueue.insert(std::make_shared<int>(i));
        cout << index << " ";
    }
    cout << endl;
    
    IntMinqueueType minQueue1(10, intCompare, intGetType);
    cout << "依次插入10,9,8,7,6,5,4,3,2,1返回元素插入的位置:\n";
    for (int i = 10; i >= 1; --i){
        int index = minQueue1.insert(std::make_shared<int>(i));
        cout << index << " ";
    }
    cout << endl;

    IntMinqueueType minQueue2(10, intCompare, intGetType);
    cout << "依次插入1,-1,2,-2,3,-3,4,-4,5,-5返回元素插入的位置:\n";
    for (int i = 1; i <= 5; ++i){
        int index = minQueue2.insert(std::make_shared<int>(i));
        cout << index << " ";
        index = minQueue2.insert(std::make_shared<int>(-i));
        cout << index << " ";
    }
    cout << endl;

    IntMinqueueType minQueue3(10, intCompare, intGetType);
    cout << "依次插入1,1,2,2,3,3,4,4,5,5返回元素插入的位置:\n";
    for (int i = 1; i <= 5; ++i){
        int index = minQueue3.insert(std::make_shared<int>(i));
        cout << index << " ";
        index = minQueue3.insert(std::make_shared<int>(i));
        cout << index << " ";
    }
    cout << endl;
}

// 测试最小优先队列的成员函数min
void minTest()
{
    cout << "*************MinQueue成员函数min的测试********************\n";
    IntMinqueueType minQueue(10, intCompare, intGetType);
    cout << "在序列: ";
    for (int i = 1; i <= 20; ++i){
        cout << i << " ";
        minQueue.insert(std::make_shared<int>(i));
    }
    auto result = minQueue.min();
    cout << "\n最小值为: " << *result << endl;

    IntMinqueueType minQueue1(10, intCompare, intGetType);
    cout << "在序列: ";
    for (int i = 10; i >= 1; --i){
        cout << i << " ";
        minQueue1.insert(std::make_shared<int>(i));
    }
    result = minQueue1.min();
    cout << "\n最小值为: " << *result << endl;
    
    IntMinqueueType minQueue2(10, intCompare, intGetType);
    cout << "在序列: ";
    for (int i = 1; i <= 5; ++i){
        cout << i << " ";
        minQueue2.insert(std::make_shared<int>(i));
        cout << i << " ";
        minQueue2.insert(std::make_shared<int>(i));
    }
    result = minQueue2.min();
    cout << "\n最小值为: " << *result << endl;
    
    IntMinqueueType minQueue3(10, intCompare, intGetType);
    cout << "在序列: ";
    for (int i = 1; i <= 5; ++i){
        cout << i << " ";
        minQueue3.insert(std::make_shared<int>(i));
        cout << -i << " ";
        minQueue3.insert(std::make_shared<int>(-i));
    }
    result = minQueue3.min();
    cout << "\n最小值为: " << *result << endl;
}

// 测试最小优先队列的成员函数extract_min
void extract_minTest()
{
    
    cout << "*************MinQueue成员函数extract_min的测试********************\n";
    IntMinqueueType minQueue(10, intCompare, intGetType);
    cout << "在序列: ";
    for (int i = 1; i <= 20; ++i){
        cout << i << " ";
        minQueue.insert(std::make_shared<int>(i));
    }
    for (int i = 1; i <= 20; ++i){
        auto result = minQueue.extract_min();
        cout << "\n最小值为(且删除这个最小值): " << *result << endl;
    }

    
    IntMinqueueType minQueue1(10, intCompare, intGetType);
    cout << "在序列: ";
    for (int i = 10; i >= 1; --i){
        cout << i << " ";
        minQueue1.insert(std::make_shared<int>(i));
    }
    for (int i = 1; i <= 10; ++i){
        auto result = minQueue1.extract_min();
        cout << "\n最小值为(且删除这个最小值): " << *result << endl;
    }
        
    IntMinqueueType minQueue2(10, intCompare, intGetType);
    cout << "在序列: ";
    for (int i = 1; i <= 5; ++i){
        cout << i << " ";
        minQueue2.insert(std::make_shared<int>(i));
        cout << i << " ";
        minQueue2.insert(std::make_shared<int>(i));
    }
    for (int i = 1; i <= 10; ++i){
        auto result = minQueue2.extract_min();
        cout << "\n最小值为(且删除这个最小值): " << *result << endl;
    }

    IntMinqueueType minQueue3(10, intCompare, intGetType);
    cout << "在序列: ";
    for (int i = 1; i <= 5; ++i){
        cout << i << " ";
        minQueue3.insert(std::make_shared<int>(i));
        cout << -i << " ";
        minQueue3.insert(std::make_shared<int>(-i));
    }
    for (int i = 1; i <= 10; ++i){
        auto result = minQueue3.extract_min();
        cout << "\n最小值为(且删除这个最小值): " << *result << endl;
    }   
}

int main()
{ 
    cout << "*******************************int型整数的测试***********************************" << endl;
    insertTest();
    minTest();
    extract_minTest();

    return 0;
}
