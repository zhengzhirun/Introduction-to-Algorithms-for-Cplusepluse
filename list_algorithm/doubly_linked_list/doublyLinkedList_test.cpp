/*************************************************************************
	> File Name: doublyLinkedList_test.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月15日 星期四 10时28分24秒
 ************************************************************************/

#include <iostream>
using std::cout;    using std::endl;
#include "doublyLinkedList.h"
#include "../doublyLinkedListNode/doublyLinkedListNode.h"
typedef DoublyLinkedList<DoublyLinkedListNode<int>> IntList;
void insertBack_test()
{
    IntList intlist;
    cout << "依次向链表尾部中插入:\n "; 
    for (int i = 0; i <= 20; ++i){
        cout << i << " ";
        intlist.insertBack(i);
    }
    cout << "\n顺序遍历列表:\n ";
    intlist.order_print();
    cout << "逆序遍历链表:\n";
    intlist.reverse_order_print();
}

void insertFront_test()
{
    IntList intlist;
    cout << "依次向链表的头部插入:\n";
    for (int i = 0; i <= 20; ++i){
        cout << i << " ";
        intlist.insertFront(i);
    }
    cout << "\n顺序遍历链表:\n";
    intlist.order_print();
    cout << "逆序遍历链表:\n";
    intlist.reverse_order_print();
}

void search_test()
{
    IntList intlist;
    cout << "依次向链表尾部中插入:\n "; 
    for (int i = 0; i <= 20; ++i){
        cout << i << " ";
        intlist.insertBack(i);
    }
    auto value = intlist.search(10);
    cout << "\n已找到链表中指定的元素: " << value->key << endl;
}

void deleteList_test()
{
    IntList intlist;
    cout << "依次向链表尾部中插入:\n "; 
    for (int i = 0; i <= 20; ++i){
        cout << i << " ";
        intlist.insertBack(i);
    }
    auto value = intlist.search(10);
    bool sign = intlist.deleteList(value);
    cout << "\n删除元素是否成功: " << sign << endl;
    intlist.order_print();
    intlist.reverse_order_print();
}

void insert_test()
{
    IntList intlist;
    cout << "依次向链表尾部中插入:\n "; 
    for (int i = 0; i <= 20; ++i){
        cout << i << " ";
        intlist.insertBack(i);
    }
    auto value = intlist.search(10);
    bool sign = intlist.insert(value, 100);
    cout << "\n插入元素是否成功: " << sign << endl;
    intlist.order_print();
    intlist.reverse_order_print();
}
int main()
{
    cout << "*****************双向链表尾部插入****************************\n";
    insertBack_test();
    cout << "*****************双向链表头部插入****************************\n";
    insertFront_test();
    cout << "*****************双向链表查询插入****************************\n";
    search_test();
    cout << "*****************双向链表删除操作****************************\n";
    deleteList_test();
    cout << "*****************双向链表插入操作****************************\n";
    insert_test();

    return 0;
}

