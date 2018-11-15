/*************************************************************************
	> File Name: queue_test.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月13日 星期二 15时57分16秒
 ************************************************************************/

#include <iostream>
using std::cout;    using std::endl;
#include "queue.h"

typedef Queue<int> IntQueue;
typedef Queue<double> DoubleQueue;

void intTest()
{
    IntQueue intQueue(20);
    cout << "插入的元素分别为: " << endl;
    for (int i = 0; i != 22; ++i){
        cout << i << endl;
        intQueue.enQueue(std::make_shared<int>(i));
    }
    cout << "依次出队: " << endl;
    for (int i = 0; i != 22; ++i){
        auto val_ptr = intQueue.deQueue();
        if (val_ptr)
            cout << *val_ptr << " ";
    }
}

void doubleTest()
{
    DoubleQueue doubleQueue(20);
    cout << "插入的元素分别为: " << endl;
    for (int i = 0; i != 22; ++i){
        cout << i*0.01 << endl;
        doubleQueue.enQueue(std::make_shared<double>(i*0.01));
    }
    cout << "依次出队: " << endl;
    for (int i = 0; i != 22; ++i){
        auto val_ptr = doubleQueue.deQueue();
        if (val_ptr)
            cout << *val_ptr << " ";
    }
}
int main()
{
    intTest();
    doubleTest();

    return 0;
}
