/*************************************************************************
	> File Name: RedBlackTreeNode.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月26日 星期一 16时04分21秒
 ************************************************************************/
#ifndef _REDBLACKTREENODE_H
#define _REDBLACKTREENODE_H
#include <memory>
#include <sstream>
#include <string>
// BinaryTreeNode 红黑树的节点 算法导论第13章
/*
 * 任何一个节点都有两个强引用指向左右子节点,以及一个弱引用指向它的父节点.节点
 * 还有一个'key'成员包含具体的数据,以及'color'成员包含节点的颜色.
*/
    // 红黑树节点的颜色
    enum COLOR{
        RED = 0, // 红色节点
        BLACK = 1, // 黑色节点
    };
template<typename KType> 
struct RedBlackTreeNode
{
public:

    typedef KType KeyType;  //节点保存的数据类型
    //**************************构造函数**********************************
    //默认构造函数,所有的成员变量都采用默认值
    RedBlackTreeNode():
        parent(std::weak_ptr<RedBlackTreeNode>()),
        lchild(std::shared_ptr<RedBlackTreeNode>()),
        rchild(std::shared_ptr<RedBlackTreeNode>()),
        key(KeyType()),
        color(BLACK)
    {  }
    //显式构造函数
    /*
     * \parameter keyvalue: 节点要保存的数据内容.
     * 指定'key'成员需要赋值的数据.
    */
    explicit RedBlackTreeNode(const KeyType& keyvalue):
        parent(std::weak_ptr<RedBlackTreeNode>()),
        lchild(std::shared_ptr<RedBlackTreeNode>()),
        rchild(std::shared_ptr<RedBlackTreeNode>()),
        key(keyvalue),
        color(BLACK)
    {  }
    //**************************成员函数**********************************
    // to_string: 返回该节点的字符串描述
    /*
     * \return: 本节点的描述字符串
     * 该函数打印本节点的'key',以及父节点(若存在),子节点(若存在),的'key'.
    */
    virtual std::string to_string()
    {
        std::ostringstream os;
        os << "node: " << key;
        if (auto shared_p = parent.lock())
            os << "\n\t parent: " << shared_p->key;
        else
            os << "\n\t parent: " << "null_ptr";

        os << "\n\t left_child: ";
        if (lchild)
            os << lchild->key << " color: " << lchild->color;
        else
            os << "nullptr";

        os << "\n\t right_child: ";
        if (rchild)
            os << rchild->key << " color: " << rchild->color;
        else
            os << "nullptr";

        os << "\n\t color: " << color;
        
        return os.str();
    }
    // to_xml: 返回以该节点为根的子树的'xml'描述
    /*
     * \return: 本节点子树的'xml'描述字符串. 
     * 该函数返回以本节点为根的子树的'xml'描述.对子节点递归调用从而生成"xml"数据.
    */
    virtual std::string to_xml()
    {
        std::ostringstream os;
        os << "\n<node>" << key << "\n";
        if (auto shared_p = parent.lock())
            os << "\t <parent>" << shared_p->key << "</parent>";
        else
            os << "\t <parent>" << "null_ptr" << "</parent>";

        os << "\n\t <left_child>";
        if (lchild)
            os << lchild->to_xml();
        else
            os << "nullptr";
        os << "</left_child>";

        os << "\n\t <right_child>";
        if (rchild)
            os << rchild->to_xml();
        else
            os << "nullptr";
        os << "</right_child>";

        os << "\n\t<color>" << color << "</color>";

        return os.str();
    }
    // is_left_child: 判断本节点是否是左子节点
    /*
     * \return 返回'true'或'false'.
     * 该函数判断本节点是否是左子节点.如果本节点的父节点为空,则返回'false';
     *      如果本节点的父节点非空且本节点是父节点的左子节点,则返回'true';否则
     *      返回'false'.
    */
    bool is_left_child()
    {
        if (auto shared_p = parent.lock()){
            if (this == shared_p->lchild.get())
                return true;
        }
        return false;
    }
    // is_right_child: 判断本节点是否是右节点
    /*
     * \retrun 返回'false'或'true'.
     * 该函数判断本节点是否是右子节点,如果本节点的父节点为空,则返回'false';
     *      如果本节点的父节点非空且本节点是父节点的右子节点,则返回'true';否则
     *      返回'false'.
    */
    bool is_right_child()
    {
        if (auto shared_p = parent.lock()){
            if (this == shared_p->rchild.get())
                return true;
        } 
        return false;
    }
    //**************************数据结构**********************************
    std::weak_ptr<RedBlackTreeNode> parent;   //节点的父节点的弱引用
    std::shared_ptr<RedBlackTreeNode> lchild;     //节点的左子节点的强引用
    std::shared_ptr<RedBlackTreeNode> rchild;     //节点的右子节点的强引用
    KeyType key;    //节点的保存的数据
    COLOR color;    //保存节点的颜色
};
#endif
