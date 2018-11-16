/*************************************************************************
	> File Name: circularList.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月16日 星期五 10时00分26秒
 ************************************************************************/

#ifndef _CIRCULARLIST_H
#define _CIRCULARLIST_H
#include <memory>
#include <iostream>
#include "../doublyLinkedListNode/doublyLinkedListNode.h"
// CircularList: 带有哨兵的循环链表
/*
 * nil: 哨兵双向循环链表.
 * 待有哨兵双向循环链表的优势就在于边界条件的处理.
*/
template<typename NodeT>
class CircularList
{
public:
    typedef NodeT NodeType;     // 链表的节点类型
    typedef typename NodeT::KeyType KeyType;        // 链表节点存储的数据类型
    //*******************************构造函数*****************************
    CircularList()
    {  
        auto data = std::make_shared<NodeType>(0);
        nil = data;
        nil->next = data;
        nil->prev = data;
    }
    //*******************************成员函数*****************************   
    // insertBack: 不断的在nil->next插入元素
    /*
     * \parameter key: 待插入的元素;
     * \return sign(标志插入是否成功).
    */
    bool insertBack(const KeyType &key)
    {
        bool sign = false;
        auto data = std::make_shared<NodeType>(key);
        data->next = nil->next;
        data->prev = nil;
        nil->next->prev = data;
        nil->next = data;
        sign = true;

        return sign;
    }
    // insert: 在循环链表给定的位置后面插入元素
    /*
     * \parameter ptr: 给定循环链表中的位置;
     * \parameter key: 在给定位置ptr后面插入key;
     * \return sign(指示是否插入成功).
     * 算法复杂度: O(1).
    */
    bool insert(std::shared_ptr<NodeType> &ptr ,const KeyType &key)
    {
        bool sign = false;
        if (ptr == NULL)
            return sign;
        auto data = std::make_shared<NodeType>(key);
        data->next = ptr->next;
        data->prev = ptr;
        ptr->next->prev = data;
        ptr->next = data;
        sign = true;

        return sign;
    }
    // search: 在循环链表中查找给定的元素
    /*
     * \parameter key: 在链表中查找'key';
     * \return 返回'key'所在的位置.
     * 算法复杂度: O(N).
    */
    std::shared_ptr<NodeType> search(const KeyType &key)
    {
        auto current = nil->next;
        while(current != nil && current->key != key)
            current = current->next;
        if (current == nil)
            return std::make_shared<NodeType>();
        else
        return current;
    }
    // deleteList: 删除指定位置的元素
    /*
     * \parameter ptr: 删除ptr指向的元素;
     * \return sign(标志是否删除成功).
     * 算法复杂度: O(1).
    */
    bool deleteList(std::shared_ptr<NodeType> &ptr)
    {
        bool sign = false;
        ptr->next->prev = ptr->prev;
        ptr->prev->next = ptr->next;
        ptr.reset();
        sign = true;
        return sign;
    }
    // order_print: 顺序遍历链表(从哨兵的next开始)
    /*
     * 当nil->next==nil的时候循环链表为空链表.
    */
    void order_print()
    {
        if (nil == nil->next){
            std::cout << "The list is empty!\n";
            return;
        }
        for (auto current = nil->next; current != nil; current = current->next)
            std::cout << current->key << " ";
        std::cout << std::endl;
    }
    // reverse_order_print: 逆序遍历链表(从哨兵的prev开始)
    /*
     * 当nil->prev=nil的时候循环链表为空链表.
    */
    void reverse_order_print()
    {
        if (nil == nil->prev){
            std::cout << "The list is empty!\n";
            return;
        }
        for (auto current = nil->prev; current != nil; current = current->prev)
            std::cout << current->key << " ";
        std::cout << std::endl;
    }
private:
    //*******************************数据结构*****************************
    std::shared_ptr<NodeType> nil;  // 哨兵
};
#endif
