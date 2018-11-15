/*************************************************************************
	> File Name: binarytree.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月14日 星期三 14时09分53秒
 ************************************************************************/

#ifndef _BINARYTREE_H
#define _BINARYTREE_H
#include <memory>
#include "../binarytreeNode/binarytreeNode.h"
// BinataryTree: 二叉树, 算法导论10.4
/*
 * 二叉树通过一个root(或引用)指向一个节点对象. 当root为空的时候,树为空.
*/
template<typename NodeT>
struct BinaryTree
{
    typedef NodeT NodeType;     // 树的节点类型
    typedef typename NodeT::KeyType KeyType;    // 树的节点存储数据的类型
    //*****************************构造函数*******************************
    // 默认构造函数
    /*
     * 新建的二叉树默认为空.
    */
    BinaryTree(): root(std::shared_ptr<NodeType>()) {}
    // to_xml: 返回树的'xml'描述.
    /*
     * \return: 返回树的'xml'描述的字符串.
     * 该函数获取本树的'xml'描述.
    */
    std::string to_xml()
    {
        if (root)
            return root->to_xml();
        else
            return "tree is empty!";
    }
    //*****************************数据结构*******************************
    std::shared_ptr<NodeType> root;     // 树的根节点,是一个指向节点对象的强引用
};
// preorder_walk: 二叉树的前序遍历
/*
 * \parameter root: 二叉树的根节点, 强引用;
 * \parameter action: 对二叉树节点执行的操作;
 * \return void.
 * 本函数执行对二叉树的前序遍历,遍历时执行指定的操作.
 * 算法:
 *      --对本节点执行操作;
 *      --对左子节点前序遍历;
 *      --对右子节点前序遍历.
 * 算法性能: 时间复杂度为O(N), 空间复杂度为O(N).
*/
template<typename NodeType, typename ActionType = std::function<void (typename NodeType::KeyType)>>
void preorder_walk(std::shared_ptr<NodeType> root,
                   ActionType action=[](typename NodeType::KeyType){})
{
    if (root){
        action(root->key);
        if (root->lchild) preorder_walk(root->lchild, action);
        if (root->rchild) preorder_walk(root->rchild, action);
    }
}
// inorder_walk: 二叉树的中序遍历
/*
 * \parameter root: 二叉树的根节点,强引用;
 * \parameter action: 对二叉树节点执行的操作;
 * \return void.
 * 本函数执行对二叉树的中序遍历,遍历时执行指定的操作.
 * 算法:
 *      --对左子节点前序遍历;
 *      --对本节点执行操作;
 *      --对右子节点前序遍历;
 * 算法性能: 时间复杂度为O(N), 空间复杂度为O(N).
*/
template<typename NodeType, typename ActionType = std::function<void (typename NodeType::KeyType)>>
void inorder_walk(std::shared_ptr<NodeType> root,
                  ActionType action = [](typename NodeType::KeyType){})
{
    if (root){
        if (root->lchild) inorder_walk(root->lchild, action);
        action(root->key);
        if(root->rchild) inorder_walk(root->rchild, action);
    }
}
// postorder_walk: 二叉树的后序遍历
/*
 * \parameter root: 二叉树的根节点,强引用;
 * \parameter action: 对二叉树节点执行的操作;
 * \return void.
 * 本函数执行对二叉树的后序遍历, 遍历时执行指定的操作.
 * 算法:
 *      --对左子节点后续遍历;
 *      --对右子节点后续遍历;
 *      --对本子节点操作.
 * 算法性能: 时间复杂度为O(N), 空间复杂度为O(N).
*/
template<typename NodeType, typename ActionType = std::function<void (typename NodeType::KeyType)>>
void postorder_walk(std::shared_ptr<NodeType> root,
                    ActionType action = [](typename NodeType::KeyType){})
{
    if (root){
        if (root->lchild) postorder_walk(root->lchild, action);
        if (root->rchild) postorder_walk(root->rchild, action);
        action(root->key);
    }
}
#endif
