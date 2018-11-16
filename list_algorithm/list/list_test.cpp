/*************************************************************************
	> File Name: list_test.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月15日 星期四 19时08分15秒
 ************************************************************************/

#include <iostream>
#include "list.h"
using std::cout;    using std::endl;

typedef List<ListNode<int>> IntList;
void insertFront_test()
{
    IntList intlist;
    cout << "依次向链表头部插入: \n";
    for (int i = 0; i <= 20; ++i){
        cout << i << " ";
        intlist.insertFront(i);
    }
    cout << "\n顺序遍历链表:\n";
    intlist.order_print();
}
void insertBack_test()
{
    IntList intlist;
    cout << "依次向链表尾部插入: \n";
    for (int i = 0; i <= 20; ++i){
        cout << i << " ";
        intlist.insertBack(i);
    }
    cout << "\n顺序遍历链表:\n";
    intlist.order_print();
}
void search_test()
{
    IntList intlist;
    cout << "依次向链表尾部插入: \n";
    for (int i = 0; i <= 20; ++i){
        cout << i << " ";
        intlist.insertBack(i);
    }
    cout << "\n遍历单向链表查找给定元素10:\n ";
    cout << (intlist.search(10)->key) << endl;
}

void insert_test()
{
    IntList intlist;
    cout << "依次向链表尾部插入: \n";
    for (int i = 0; i <= 20; ++i){
        cout << i << " ";
        intlist.insertBack(i);
    }
    auto data_ptr = intlist.search(10);
    cout << "\n在10后面插入100:\n" << endl;
    cout << "插入是否成功: " << intlist.insert(data_ptr,100) << endl;
    // 遍历链表
    intlist.order_print();
}

void deleteList_test()
{
    IntList intlist;
    cout << "依次向链表尾部插入: \n";
    for (int i = 0; i <= 20; ++i){
        cout << i << " ";
        intlist.insertBack(i);
    }
    auto data_ptr = intlist.search(10);
    cout << "\n删除元素10:\n" << endl;
    cout << "删除是否成功: " << intlist.deleteList(data_ptr) << endl;
    // 遍历链表
    intlist.order_print();
}

int main()
{
    cout << "************************单向链表头部插入*********************\n";
    insertFront_test();
    cout << "************************单向链表尾部插入*********************\n";
    insertBack_test();
    cout << "************************单向链表查找*************************\n";
    search_test();
    cout << "************************单向链表插入*********************\n";
    insert_test();
    cout << "************************单向链表的删除*******************\n";
    deleteList_test();

    return 0;
}
