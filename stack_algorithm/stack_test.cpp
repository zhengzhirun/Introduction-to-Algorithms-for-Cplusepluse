/*************************************************************************
	> File Name: stack_test.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月13日 星期二 10时51分54秒
 ************************************************************************/

#include <iostream>
using std::cout;    using std::endl;
#include "stack.h"

typedef Stack<int> IntStack;
typedef Stack<double> DoubleStack;

void intTest()
{ 
    IntStack intStack(0);
    // 测试栈是否为空
    cout << "初始化后栈是否为空: " << intStack.empty() << endl;
    // 向栈中插入元素
    cout << "依次向栈中插入元素: \n";
    for (int i = 0; i <= 10; ++i){
        cout << i << " ";
        intStack.push(std::make_shared<int>(i));
    }
    cout << endl;
    // 弹出栈中所有元素后
    cout << "依次弹出栈中所有元素: \n"; 
    while (intStack.empty())
        cout << *intStack.pop() << " ";
    cout << endl;
}

void doubleTest()
{
    DoubleStack doubleStack(0);
    // 测试栈是否为空
    cout << "初始化后栈是否为空: " << doubleStack.empty() << endl;
    // 向栈中插入元素
    cout << "依次向栈中插入元素: " << endl;
    for (int i = 0; i <= 10; ++i){
        double val = i * 0.01;
        doubleStack.push(std::make_shared<double>(val));
        cout << val << " ";
    }
    cout << endl;
    cout << "依次弹出栈中元素: \n";
    while (doubleStack.empty())
        cout << *doubleStack.pop() << " ";
    cout << endl;
}


int main()
{
    cout << "*******************对int型数据测试***************************\n";
    intTest();
    cout << "*****************对double型数据测试**************************\n";
    doubleTest();

    return 0;
}
