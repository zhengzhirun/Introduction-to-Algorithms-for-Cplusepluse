/*************************************************************************
	> File Name: circularList_test.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月16日 星期五 10时57分40秒
 ************************************************************************/

#include <iostream>
using std::cout;    using std::endl;
#include "circularList.h"
#include "../doublyLinkedListNode/doublyLinkedListNode.h"
typedef CircularList<DoublyLinkedListNode<int>> IntList;

void initList_test()
{
    IntList intlist;
    intlist.order_print();
    intlist.reverse_order_print();
}

void insertBack_test()
{
    IntList intlist;
    cout << "依次向循环链表哨兵后面插入: \n";
    for (int i = 1; i <= 20; ++i){
        cout << i << " ";
        intlist.insertBack(i);
    }
    cout << "\n正序输出: \n";
    intlist.order_print();
    cout << "逆序输出: \n";
    intlist.reverse_order_print();
}

void search_test()
{
    IntList intlist;
    cout << "依次向循环链表哨兵后面插入: \n";
    for (int i = 1; i <= 20; ++i){
        cout << i << " ";
        intlist.insertBack(i);
    }
    auto value_ptr = intlist.search(10);
    cout << "\n在序列中是否找到10:  " << value_ptr->key << endl; 
}

void insert_test()
{
    IntList intlist;
    cout << "依次向循环链表哨兵后面插入: \n";
    for (int i = 1; i <= 20; ++i){
        cout << i << " ";
        intlist.insertBack(i);
    }
    auto value_ptr = intlist.search(10);
    intlist.insert(value_ptr, 100);
    cout << "\n正序输出: \n";
    intlist.order_print();
    cout << "逆序输出:\n";
    intlist.reverse_order_print();
}

void deleteList_test()
{
    IntList intlist;
    cout << "依次向循环链表哨兵后面插入: \n";
    for (int i = 1; i <= 20; ++i){
        cout << i << " ";
        intlist.insertBack(i);
    }
    auto value_ptr = intlist.search(10);
    bool sign = intlist.deleteList(value_ptr);
    cout << "\n正序输出: \n";
    intlist.order_print();
    cout << "逆序输出:\n";
    intlist.reverse_order_print();
}
int main()
{
    cout << "***************************循环链表默认构造函数***************************\n";
    initList_test();
    cout << "***************************循环链表在哨兵后面插入*************************\n";
    insertBack_test();
    cout << "*******************************循环链表查找*******************************\n";
    search_test();
    cout << "*******************************循环链表插入*******************************\n";
    insert_test();
    cout << "*******************************循环链表删除*******************************\n";
    deleteList_test();

    return 0;
}

