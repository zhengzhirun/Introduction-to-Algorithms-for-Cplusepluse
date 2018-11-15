/*************************************************************************
	> File Name: doublyLinkedListNode_test.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月14日 星期三 21时59分35秒
 ************************************************************************/

#include <iostream>
using std::cout;    using std::endl;
#include "doublyLinkedListNode.h"
typedef DoublyLinkedListNode<int> IntList;

void Test()
{
    DoublyLinkedListNode<int> intList(DoublyLinkedListNode<int>(11));
    cout << intList.to_string() << endl;
}

void Test1()
{
    DoublyLinkedListNode<int> intList;
    cout << intList.to_string() << endl;
}

void Test2()
{
    typedef DoublyLinkedListNode<int> Node;
    auto head = std::make_shared<Node>(0);
    head->next = std::make_shared<Node>(1);
    head->next->next = std::make_shared<Node>(2);

    head->next->prev = head;
    head->next->next->prev = head->next;
    cout << head->next->to_string() << endl;

}

int main()
{
    Test();
    Test1();
    Test2();

    return 0;
}
