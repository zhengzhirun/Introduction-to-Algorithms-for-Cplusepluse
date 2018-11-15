/*************************************************************************
	> File Name: ListNode.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月15日 星期四 16时06分17秒
 ************************************************************************/

#ifndef _LISTNODE_H
#define _LISTNODE_H
#include <memory>
#include <string>
#include <sstream>
// ListNode: 单向链表的节点 算法导论10.2
/*
 *
*/
template<typename KType>
struct ListNode
{
    typedef KType KeyType;
    //*******************************构造函数*****************************
    // 默认构造函数,所有的数据成员变量都采用默认值
    ListNode():
        key(KeyType()),
        next(std::shared_ptr<ListNode>())
    {  }
    // 显式构造函数
    /*
     * \parameter val: 节点要保存的数据内容.
     * 指定'key'成员需要赋值的数据.
    */
    explicit ListNode(const KeyType &val):
        key(val),
        next(std::shared_ptr<ListNode>())
    {  }
    //*******************************成员函数*****************************
    // to_string: 返回该节点的字符串描述
    /*
     * \return: 返回本节点的描述字符串.
     * 该函数打印本节点的'key',以及后继节点(若存在)的'key'.
    */
    virtual std::string to_string()
    {
        std::ostringstream os;
        os << "node " << key;
        os << "\n\tnext_node: ";
        if (next)
            os << next->key;
        else
            os << "nullptr";
        return os.str();
    }
    //*******************************数据结构*****************************
    KeyType key;    // 链表的数据
    std::shared_ptr<ListNode> next;     // 后继指针
};
#endif
