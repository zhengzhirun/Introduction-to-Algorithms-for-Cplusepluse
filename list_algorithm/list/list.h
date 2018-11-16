/*************************************************************************
    > File Name: list.h
    > Author: ZhirunZheng 
    > Mail: jiangxizhengzhirun@163.com 
    > Created Time: 2018年11月15日 星期四 16时41分49秒
 ************************************************************************/

#ifndef _LIST_H
#define _LIST_H
#include <memory>
#include <iostream>
#include "../listNode/ListNode.h"
// List: 单向链表 算法导论10.2
/*
 * \parameter head: 表头指针;
 * insertBack(x): 在链表的尾部插入元素;
 * insertFront(x): 在链表的头部插入元素;
 * insert(ptr,x): 在给定指针ptr后面插入元素x;
 * search(x): 在链表中查找元素x;
 * deleteList(ptr): 在链表中删除指针ptr指向的元素;
 * order_print(): 顺序打印链表中的元素.
*/
template<typename NodeT>
class List
{
public:
    typedef NodeT NodeType;     // 链表的节点类型
    typedef typename NodeT::KeyType KeyType;    // 链表节点存储的数据类型
    //******************************默认构造函数**************************
    List():
        head(std::shared_ptr<NodeType>())
    {  }
    //******************************成员函数******************************
    // insertFront:在链表的头部插入元素
    /*
     * \parameter key:待插入的元素;
     * \return sign(标志是否插入成功).
     * 算法复杂度为O(1).
    */
    bool insertFront(const KeyType &key)
    {
        bool sign = false;
        if (head == NULL){
            auto data = std::make_shared<NodeType>(key);
            head = data;
            sign = true;
        }
        else{
            auto data = std::make_shared<NodeType>(key);
            data->next = head;
            head = data;
            sign = true;
        }
        return sign;
    }
    // insertBack:在链表的尾部插入元素
    /*
     * \parameter key:带插入的元素;
     * \return sign(标志是否插入成功).
     * 算法复杂度为O(N).
    */
    bool insertBack(const KeyType &key)
    {
        bool sign = false;
        if (head == NULL){
            auto data = std::make_shared<NodeType>(key);
            head = data;
            sign = true;
        }
        else{
            auto current = head;
            while (current->next != NULL)
                current = current->next;
            auto data = std::make_shared<NodeType>(key);
            current->next = data;
            sign = true;
        }
        return sign;
    }
    // insert: 在给定位置后面插入元素
    /*
     * \parameter val_ptr: 在指针val_ptr后面插入key;
     * \parameter key: 在指针val_ptr后面插入key;
     * \return sign(指示是否插入成功).
     * 算法复杂度: O(N).
    */
    bool insert(const std::shared_ptr<NodeType> &val_ptr, const KeyType &key)
    {
        if (!head){
            std::cout << "The list is empty!\n";
            return false;
        }
        if (!val_ptr){
            std::cout << "此指针为空!\n";
            return false;
        }
        bool sign = false;
        auto current = head;
        while (current != val_ptr && current != NULL) 
            current = current->next;
        if (current != NULL){
            auto data = std::make_shared<NodeType>(key);
            data->next = current->next;
            current->next = data;
            sign = true;
        }
        else
            std::cout << "没有该元素" << std::endl;
        return sign;
    }
    // search: 简单的线性搜索算法
    /*
     * \parameter key: 待查找的元素key;
     * \return 指向已查找到元素的指针.
     * 算法复杂度: O(N).
    */
    std::shared_ptr<NodeType> search(const KeyType &key)
    {
        if (head == NULL){
            std::cout << "The list is empty!\n";
            return std::shared_ptr<NodeType>();
        }
        auto current = head;
        while (current != NULL && current->key != key)
            current = current->next;
        if (current != NULL)
            return current;
        else
            return std::shared_ptr<NodeType>();
    }
    // deleteList: 单向链表的删除操作
    /*
     * \parameter val_ptr: 删除列表中val_ptr指向的元素;
     * \return sign(标志删除是否成功).
     * 算法复杂度: O(N).
    */
    bool deleteList(std::shared_ptr<NodeType> &val_ptr)
    {
        if (head == NULL){
            std::cout << "The list is empty!";
            return false;
        }
        if (val_ptr == NULL){
            std::cout << "此指针为空!";
            return false;
        }
        // 删除头指针的情况
        if (val_ptr == head){
            head = val_ptr->next;
            val_ptr.reset();
            return true;
        }
        auto sign = false;
        auto current = head;
        auto front_ptr = head;
        while (current != val_ptr && current != NULL){
            front_ptr = current;
            current = current->next;
        }
        if (current == NULL)
            std::cout << "未找到此指针\n"; 
        else{
            front_ptr->next = current->next;
            val_ptr.reset();
            sign = true;
        }
        return sign;
    }
    // order_print: 顺序遍历链表
    /*
     * \return void.
     * 顺序遍历单向链表,时间复杂度为O(N).
    */
    void order_print()
    {
        if (head == NULL)
            std::cout << "The list is empty!\n";
        else{
            for (auto current = head; current != NULL; current = current->next)
                std::cout << current->key << " ";
            std::cout << std::endl;
        }
    }
private:
    //******************************数据结构******************************
    std::shared_ptr<NodeType> head;     // 链表的头指针
};
#endif
