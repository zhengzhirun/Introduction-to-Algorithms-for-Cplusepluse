/*************************************************************************
	> File Name: ListNode_test.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月15日 星期四 16时22分29秒
 ************************************************************************/

#include <iostream>
using std::cout;    using std::endl;
#include "ListNode.h"

typedef ListNode<int> IntList;
void Test()
{
    IntList intlist;
    cout << intlist.to_string() << endl;
}
void Test1()
{
    auto head = std::make_shared<IntList>(1);
    head->next = std::make_shared<IntList>(2);
    cout << head->to_string() << endl;
    cout << head->next->to_string() << endl;

}

int main()
{
    Test();
    Test1();

    return 0;
}

