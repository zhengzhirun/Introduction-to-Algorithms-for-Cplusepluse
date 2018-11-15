/*************************************************************************
	> File Name: list.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月15日 星期四 16时41分49秒
 ************************************************************************/

#ifndef _LIST_H
#define _LIST_H
#include "../listNode/ListNode.h"
// List: 单向链表 算法导论10.2
template<typename NodeT>
class List
{
public:
    typedef NodeT NodeType;     // 链表的节点类型
    typedef typename NodeT::KeyType KeyType;    // 链表节点存储的数据类型
    //******************************默认构造函数**************************

private:
    //******************************数据结构******************************
    std::shared_ptr<NodeType> head;     // 链表的头指针
};


#endif
