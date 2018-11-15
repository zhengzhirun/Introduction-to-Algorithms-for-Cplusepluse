/*************************************************************************
	> File Name: doublyLinkedList.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月14日 星期三 22时22分22秒
 ************************************************************************/

#ifndef _DOUBLYLINKEDLIST_H
#define _DOUBLYLINKEDLIST_H
#include "../doublyLinkedListNode/doublyLinkedListNode.h"
// DoublyLinkedList: 双向链表 算法导论10.2
/*
 * 双向链表通过head,tail指向节点对象, 其中head表示链表的头,tail表示链表的尾.
 * 当head为空的时候链表为一个空链表,当tail为空的时候链表为一个空链表.
*/
template<typename NodeT>
class DoublyLinkedList
{
public:
    typedef NodeT NodeType;     // 链表的节点类型
    typedef typename NodeT::KeyType KeyType;    // 链表节点存储数据的类型
    //******************************默认构造函数**************************
    DoublyLinkedList():
        head(std::shared_ptr<NodeType>()),
        tail(std::shared_ptr<NodeType>())
    {  }
    //******************************成员函数******************************
    // insertBack: 向双向链表的尾部插入数据
    /*
     * \parameter key: 待插入的数据;
     * \return void.
    */
    void insertBack(const KeyType &key)
    {
        // 链表为空的时候
        if (!head){
            auto data = std::make_shared<NodeType>(key);
            head = data;
            tail = data;
        }
        else{
            // 链表非空的时候
            auto data = std::make_shared<NodeType>(key);
            tail->next = data;
            tail->next->prev = tail;
            tail = data;
        }
    }
    // insertFront: 向双向链表的头部插入数据
    /*
     * \parameter key: 待插入的数据;
     * \return void.
    */
    void insertFront(const KeyType &key)
    {
        // 链表为空的时候
        if (!head){
            auto data = std::make_shared<NodeType>(key);
            head = data;
            tail = data;
        }
        else{
            // 链表非空的时候
            auto data = std::make_shared<NodeType>(key);
            head->prev = data;
            head->prev->next = head;
            head = data;
        }
    }
    // search: 采用简单的线性搜索方法
    /*
     * \parameter key: 待查询的数据;
     * \return 返回指向查询数据的指针(第一次出现的位置).
     * 线性搜索,时间复杂度为O(N).
    */
    std::shared_ptr<NodeType> search(const KeyType &key)
    {
        std::shared_ptr<NodeType> value = std::shared_ptr<NodeType>();
        if (!head)
            std::cout << "The doubly linked list is empty!\n";
        else{
            for (auto current = head; current != NULL; current = current->next){
                if (key == current->key){
                    value = current;
                    break;
                }
            }
        }
        return value;
    }
    // deleteList: 在链表中删除给定元素指针
    /*
     * \parameter value: 指向待删除元素的指针;
     * \return sign(标志删除是否成功).
     * 删除一个元素指针所耗费的时间为O(1).
    */
    bool deleteList(std::shared_ptr<NodeType> &value)
    {
        if (value == NULL)
            return false;
        bool sign = false;
        if (value == head){
            head->next->prev = std::shared_ptr<NodeType>();
            head = value->next;
            value.reset();
            sign = true;
        }
        else if (value == tail){
            tail->prev->next = std::shared_ptr<NodeType>();
            tail = value->prev;
            value.reset();
            sign = true;
        }
        else{
            value->prev->next = value->next;
            value->next->prev = value->prev;
            value.reset();
            sign = true;
        }
        return sign;
    
    }
    // insert: 在给定指针的后面插入元素
    /*
     * \parameter value: 把元素'key'插入到value指针后面;
     * \parameter key: 待插入的值;
     * \return sign(标志插入是否成功).
     * 插入一个元素所耗费的时间为O(1).
    */
    bool insert(std::shared_ptr<NodeType> &value, const KeyType key)
    {
        if (value == NULL)
            return false;
        bool sign = false;
        if (value == tail){
            insertBack(key);
            sign = true;
        }
        else{
            auto key_ptr = std::make_shared<NodeType>(key);
            key_ptr->next = value->next;
            key_ptr->prev = value;
            value->next->prev = key_ptr;
            value->next = key_ptr;
            sign = true;
        }
        return sign;
    }
    
    // order_print:顺序遍历链表
    /*
     * \return void.
     * 顺序遍历双向链表,打印其'key'.
    */
    void order_print()
    {
        if (!head)
            std::cout << "The doubly linked list is empty!\n";
        else{
            for (auto current = head; current != NULL; current = current->next)
                std::cout << current->key << " ";
            std::cout << std::endl;
        }
    }
    // reverse_order_print: 逆序遍历链表
    /*
     * \return void.
     * 逆序遍历双向链表,打印其'key'.
    */
    void reverse_order_print()
    {
        if (!head)
            std::cout << "The doubly linked list is enpty!\n";
        else{
            for (auto current = tail; current != NULL; current = current->prev)
                std::cout << current->key << " ";
            std::cout << std::endl;
        }
    }
private:
    //******************************数据结构******************************
    std::shared_ptr<NodeType> head;     // 链表的头
    std::shared_ptr<NodeType> tail;     // 链表的尾
};
#endif
