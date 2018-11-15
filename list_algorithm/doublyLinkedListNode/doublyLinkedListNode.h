/*************************************************************************
	> File Name: doublyLinkedListNode.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月14日 星期三 21时30分14秒
 ************************************************************************/

#ifndef _DOUBLYLINKEDLISTNODE_H
#define _DOUBLYLINKEDLISTNODE_H
#include <memory>
#include <sstream>
#include <string>
// DoublyLinkedListNode: 双向链表的节点 算法导论10.2
/*
 * 任何一个节点都有两个强引用指向前驱节点和后继节点.节点还有一个'key'成员包含具体的数据
*/
template<typename KType>
struct DoublyLinkedListNode
{
    typedef KType KeyType;
    //**************************构造函数**********************************
    // 默认构造函数,所有的数据成员变量都采用默认值
    DoublyLinkedListNode():
        key(KeyType()),
        prev(std::shared_ptr<DoublyLinkedListNode>()),
        next(std::shared_ptr<DoublyLinkedListNode>())
    {  }
    // 显示构造函数
    /*
     * \parameter val: 节点要保存的数据内容.
     * 指定'key'成员需要赋值的数据.
    */
    explicit DoublyLinkedListNode(const KeyType &val):
        key(val),
        prev(std::shared_ptr<DoublyLinkedListNode>()),
        next(std::shared_ptr<DoublyLinkedListNode>())
    {  }
    //**************************成员函数**********************************
    // to_string: 返回该节点的字符串描述
    /*
     * \return: 本节点的描述字符串
     * 该函数打印本节点的'key',以及前驱节点(若存在),后继节点(若存在)的'key'
    */
    virtual std::string to_string()
    {
        std::ostringstream os;
        os << "node " << key;
        
        os << "\n\t prev_node: ";
        if (prev)
            os << prev->key;
        else
            os << "nullptr";

        os << "\n\t next_node: ";
        if (next)
            os << next->key;
        else
            os << "nullptr";

        return os.str();
    }
public:
    //**************************数据结构**********************************
    KeyType key;    // 链表的数据
    std::shared_ptr<DoublyLinkedListNode> prev;     // 前驱指针
    std::shared_ptr<DoublyLinkedListNode> next;      // 后继指针
};
#endif
