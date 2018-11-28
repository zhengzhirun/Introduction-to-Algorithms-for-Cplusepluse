/*************************************************************************
	> File Name: binary_search_tree.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月24日 星期六 08时52分37秒
 ************************************************************************/

#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H
#include <memory>
#include <functional>
#include <stdexcept>
#include "../binarytreeNode/binarytreeNode.h"
// BinarySearchTree: 二叉搜索树  算法导论12章
/*
 * 二叉搜索树是一种特殊的二叉树.在二叉树中任何一个节点,该节点的左子节点值小于等于它;
 * 该节点右子节点的值大于等于它.
 * 
 * 定理12.4: 一棵有n个不同关键字的随机构建二叉搜索树的期望高度为O(logn).
 * 节点值的是节点处存储的数据的值.
*/
template<typename NodeType>
class BinarySearchTree
{
public:
    //*******************************构造函数*****************************
    typedef typename NodeType::KeyType KeyType;   // 树的节点存储数据的类型
    BinarySearchTree(): root(std::shared_ptr<NodeType>()) {  } // 默认构造函数
    ~BinarySearchTree() = default; // 析构函数
    //*******************************成员函数*****************************
    bool insert(std::shared_ptr<NodeType>);    // 二叉搜索树的插入操作
    void preorderWalk(std::shared_ptr<NodeType>, bool (*)(KeyType));    // 前序遍历
    void inorderWalk(std::shared_ptr<NodeType>, bool (*)(KeyType));   // 中序遍历
    void postorderWalk(std::shared_ptr<NodeType>, bool (*)(KeyType));   // 后序遍历
    std::shared_ptr<NodeType> minimum(const std::shared_ptr<NodeType> &); // 最小关键值元素
    std::shared_ptr<NodeType> maximum(const std::shared_ptr<NodeType> &);  // 最大关键值元素
    std::shared_ptr<NodeType> search(const NodeType);     // 查询操作
    std::shared_ptr<NodeType> successor(const std::shared_ptr<NodeType> &);    // 后继操作
    std::shared_ptr<NodeType> predecessor(const std::shared_ptr<NodeType> &);   // 前驱操作
    void remove(std::shared_ptr<NodeType>); // 二叉搜索树的删除操作(整个二叉搜索树最最最难的部分)
    void transplant(std::shared_ptr<NodeType> &, std::shared_ptr<NodeType> &); // 二叉搜索树剪切操作
    //*******************************数据结构*****************************
    std::shared_ptr<NodeType> root;     // 树的根节点,是一个指向节点类型的强引用
};

//************************************成员函数体*************************************************
// insert: 向二叉搜索树中插入节点
/*
 * \parameter node: 待插入的节点;
 * \return bool(是否插入成功的标志).
 *
 * 算法基本思想: 遍历二叉搜索树,若当前节点的值大于等于'node'的值,则向右侧遍历;
 *      若当前的值小于等于'node'的值,则向左侧遍历.直到碰到'nullptr'则挂载该节点.
 *
 * 算法时间复杂度为: O(h),其中h为树的高度.
*/
template<typename NodeType>
bool BinarySearchTree<NodeType>::insert(std::shared_ptr<NodeType> node)
{
    bool sign = true;
    if (!root)
        root = node;
    else{
        auto temp = root;
        bool left = true;   // 是否是父节点的左孩子
        auto temp_parent = std::shared_ptr<NodeType>();
        while (temp){
            temp_parent = temp;     // 指向父节点
            if (node->key < temp->key){
                temp = temp->lchild; // 向左侧遍历
                left = true;
            }
            else{
                temp = temp->rchild; // 向右侧遍历
                left = false;
            }
        }
        // 现在temp为空,则把node挂载temp->parent下面
        node->parent = temp_parent;
        if (left) temp_parent->lchild = node;
        else temp_parent->rchild = node;
    }
    return sign;
}
// preorderWalk: 二叉搜索树的前序遍历
/*
 * \parameter temp: 二叉树的根节点;
 * \parameter action: 对二叉树节点执行的操作;
 * \return void.
 *
 * 算法基本思想:
 *          --对本节点执行操作;
 *          --对左子节点前序遍历;
 *          --对右子节点前序遍历;
 *  --先序遍历中输出根的关键字在其左右子树的关键字值之后.
 * 算法性能: 时间复杂度为O(N), 空间复杂度为O(N).
*/
template<typename NodeType>
void BinarySearchTree<NodeType>::preorderWalk(std::shared_ptr<NodeType> temp, bool (*action)(KeyType))
{
    if (temp){
        action(temp->key);
        if (temp->lchild) preorderWalk(temp->lchild, action);
        if (temp->rchild) preorderWalk(temp->rchild, action);
    }
}
// inorderWalk: 二叉树的中序遍历
/*
 * \parameter temp: 二叉树的根节点;
 * \parameter action: 对二叉树节点执行的操作;
 * \return void.
 *
 * 算法基本思想:
 *          --对左子节点前序遍历;
 *          --对本节点执行操作;
 *          --对右子节点前序遍历;
 *  --输出的子树根的关键字位于其左子树的关键字和右子树的关键字值之间.
 * 算法性能: 时间复杂度为O(N), 空间复杂度为O(N).
 */
template<typename NodeType>
void BinarySearchTree<NodeType>::inorderWalk(std::shared_ptr<NodeType> temp, bool (*action)(KeyType))
{
    if (temp){
        if (temp->lchild) inorderWalk(temp->lchild, action);
        action(temp->key);
        if (temp->rchild) inorderWalk(temp->rchild,action);
    }
}
// postorderWalk: 二叉树的后序遍历
/*
 * \parameter temp: 二叉树的根节点;
 * \parameter action: 对二叉树节点执行的操作;
 * \return void.
 *
 * 算法基本思想: 
 *          --对左子节点后续遍历;
 *          --对右子节点后续遍历;
 *          --对本节点执行操作.
 *  --输出的根的关键字在其左右子树的关键字值之后.
 * 算法性能: 时间复杂度为O(N), 空间复杂度为O(N).
*/
template<typename NodeType>
void BinarySearchTree<NodeType>::postorderWalk(std::shared_ptr<NodeType> temp, bool (*action)(KeyType))
{
    if (temp){
        if (temp->lchild) postorderWalk(temp->lchild, action);
        if (temp->rchild) postorderWalk(temp->rchild, action);
        action(temp->key);
    }
}
// minimum: 以node为节点子树的最小关键值元素
/*
 * \parameter node: 以node为节点的子树;
 * \return 返回指向最小关键值元素的指针.
 * 算法基本思想: 通过从树根开始,沿着左孩子指针直到遇到一个'nullptr'.
 *      二叉搜索树的性质保证了这样做能找到树中的最小值.
 * 算法复杂度: 时间复杂度为O(h),其中h为树的高度.
*/
template<typename NodeType>
std::shared_ptr<NodeType> BinarySearchTree<NodeType>::minimum(const std::shared_ptr<NodeType> &node)
{
    auto temp = node;
    auto temp_parent = std::shared_ptr<NodeType>();
    while (temp){
        temp_parent = temp;
        temp = temp->lchild;
    }
    if (!temp_parent)
        std::cerr << "这是一棵空树!!!" << std::endl;
    return temp_parent;
}
// maximum: 以node为节点子树的最大关键值元素
/*
 * \parameter node: 以node为节点的子树;
 * \return 返回指向最大关键值元素的指针.
 * 算法基本思想: 通过从树根开始,沿着右孩子指针直到遇到一个'nullptr'.
 *      二叉搜索树的性质保证这这样做能够找到树中的最大值.
 * 算法复杂度: 时间复杂度为O(h), 其中h为树的高度.
*/
template<typename NodeType>
std::shared_ptr<NodeType> BinarySearchTree<NodeType>::maximum(const std::shared_ptr<NodeType> &node)
{
    auto temp = node;
    auto temp_parent = std::shared_ptr<NodeType>();
    while (temp){
        temp_parent = temp;
        temp = temp->rchild;
    }
    if (!temp_parent)
        std::cerr << "这是一棵空树!!!" << std::endl;
    return temp_parent;
}
// search: 二叉搜索树的查询操作
/*
 * \parameter value: 带查找的元素;
 * \return 返回指向查找到该元素的指针,如果未找到返回一个空指针.
 * 算法基本思想: 从树根开始查找,并沿着这棵树中的一条简单路径向下进行,对于遇到的每个节点temp,比较
 *      --关键字value.key与temp->key.如果两个关键字相等,查找就终止.如果value.key小于temp->key,
 *      --查找就在temp的左子树中继续,因为二叉搜索树性质蕴含了value.key不可能被存储在右子树中.
 *      --对称的,如果value.key大于temp->key查找就在右子树中继续.
 *
 * 算法性能: 算法的时间复杂度为: O(h),其中h为树的高度.
*/
template<typename NodeType>
std::shared_ptr<NodeType> BinarySearchTree<NodeType>::search(const NodeType value)
{
    auto temp = root;
    while (temp){
        if (value.key < temp->key)
            temp = temp->lchild;
        else if (value.key > temp->key)
            temp = temp->rchild;
        else
            return temp;
    }
    if (!temp)
    std::cerr << "此二叉搜索树中未找到你要查询的元素!!!" << std::endl;
    return std::shared_ptr<NodeType>();
}
// successor: 二叉搜索树指定节点的后继节点
/*
 * \parameter node: 查找节点node的后继节点;
 * \return 返回该节点后继节点的强引用或者为空.
 *
 * 给定二叉搜索树的某个节点,搜索其后继节点.所谓的某节点'node'的后继节点就是在二叉搜索树中,值大于等于
 * 'node'的所有节点中最小的那一个(排除自己).
 *
 * 一个节点'node'的后继有以下情况:
 *      --如果'node'有右子节点,则以右子节点为根的子树中最小值节点就是'node'的后继节点;
 *      --如果'node'没有右子节点,则看父节点
 *              --若'node'是父节点的左子节点;则'node'的后继节点就是'node'的父节点;
 *              --若'node'是父节点的右子节点;则'node'设置为'node->parent',不断循环直到'node'是它父亲的左
 *                子节点;此时'node'的后继节点是'node'的父节点.
 *      --注: 如果node是这棵树中的最大关键值,则返回'nullptr'.
 * 
 * 算法时间复杂度:O(h),空间复杂度O(1).其中h为树的高度.
*/
template<typename NodeType>
std::shared_ptr<NodeType> BinarySearchTree<NodeType>::successor(const std::shared_ptr<NodeType> &node)
{
    if (!node)
        throw std::invalid_argument("successor() should not be aplied on nullptr");
    // 以右子节点为根的子树中的最小值节点就是'node'的后继节点
    if(node->rchild){
        return minimum(node->rchild);
    }
    auto shared_p = node->parent.lock();    // 取出父节点
    auto temp = node;
    while (shared_p && temp->is_right_child()){
        temp = shared_p;
        shared_p = shared_p->parent.lock();
    }
    return shared_p;
}
// predecessor: 二叉搜索树指定节点的前驱节点
/*
 * \parameter node: 查找节点node的前驱节点;
 * \return 返回该节点前驱节点的强引用或者为空.
 *
 * 给定二叉搜索树的某个节点,搜索其前驱节点.所谓某节点'node'的前驱节点就是在二叉搜索树中,值小于等于'node'
 * 的所有节点中最大的那一个(排除自己).
 *
 * 一个节点'node'的前驱节点有以下情况:
 *      --如果'node'有左子节点,则以左子节点为根的子树中的最大值节点就是'node'的前驱节点;
 *      --如果'node'没有左子节点,则查看父节点
 *              --若'node'是父节点的右子节点;则'node'的前驱节点就是'node'的父节点;
 *              --若'node'是父节点的左子节点;则'node'设置为'node->parent',循环直到'node'是它父节点的右子节点
 *                ;此时'node'的前驱节点就是'node'的父节点.
 *      --注: 如果'node'是这棵树中的最小关键值,则返回'nullptr'.
 *
 * 算法时间复杂度: O(h), 空间复杂度O(1).其中h为树的高度.
*/
template<typename NodeType>
std::shared_ptr<NodeType> BinarySearchTree<NodeType>::predecessor(const std::shared_ptr<NodeType> &node)
{
    if (!node)
        throw std::invalid_argument("predecessor() should not be aplied on nullptr");
    // 以左子节点为根的子树中的最大值节点就是'node'的前驱节点
    if (node->lchild)
        return maximum(node->lchild);
    auto shared_p = node->parent.lock();    // 取出父节点
    auto temp = node;
    while (shared_p && temp->is_left_child()){
        temp = shared_p;
        shared_p = shared_p->parent.lock();
    }
    return shared_p;
}
// remove: 二叉搜索树的删除操作
/*
 * \parameter node: 要删除的节点;
 * \return: void.
 *
 * 给定节点'node',从二叉搜索树中删除它,如果'node'不在二叉搜索树中则抛出异常.
 *
 * 算法基本思想:
 *      --如果'node'是一个叶子节点:则直接删除它;
 *      --如果'node'有左子节点,但是没有右子节点: 将左子树剪切到'node'所在的位置;
 *      --如果'node'有右子节点,但是没有左子节点; 将右子树剪切到'node'所在的位置;
 *      --如果'node'既有右子节点,又有左子节点: 首先获取'node'的后继节点'next_node'(一定在'node'的右子树中);
 *          --如果'next_node'就是'node'的右子节点,则证明'next_node'没有左子节点(如果'next_node'有
 *              左子节点,那么'node'的后继节点必然不是'next_node').此时将'next_node'剪切到'node'所在
 *              的位置,并将'node'的左子树(节点)挂载到'next_node'的左子节点上.
 *          --如果'next_node'不是'node'的右子节点,则'next_node'必然位于'node'右子节点为根的子树中.且
 *              'next_node'必然没有左子节点(否则'node'的后继节点必然不是'next_node').此时将'next_node'
 *              的右子节点剪切到'next_node'位置,将'next_node'剪切到'node'的右子位置,最后执行'next_node'
 *              就是'node'的右子节点的操作.
 *
 * 算法性能: 时间复杂度为:O(h), 空间复杂度为O(1). 其中h为树的高度.
*/
template<typename NodeType>
void BinarySearchTree<NodeType>::remove(std::shared_ptr<NodeType> node)
{
    if (!node)
        throw std::invalid_argument("node remove is nullptr!!!");
    //  判定'node'必须在树中
    auto temp = root;
    while (temp && temp.get() != node.get()){
        if (node->key < temp->key)
            temp = temp->lchild;
        else
            temp = temp->rchild;
    }
    if (temp.get() != node.get())
        throw std::invalid_argument("node removed must be in tree!!!");
    // 删除过程
    // node是一个叶子节点(直接删除)
    if ((!node->lchild) && (!node->rchild)){
        auto parent_ptr = node->parent.lock();  // 获取父节点
        // 父节点非空
        if (parent_ptr){
            if (node->is_left_child())
                parent_ptr->lchild = std::shared_ptr<NodeType>();
            if (node->is_right_child())
                parent_ptr->rchild = std::shared_ptr<NodeType>();
        }
        // 父节点为空(说明这个节点为根节点 且这棵树只有这一个节点)
        else
            root = std::shared_ptr<NodeType>();
    }
    // node有左子节点但是没有右子节点
    else if (node->lchild && !node->rchild){
        transplant(node, node->lchild);     // 左子节点剪切到node位置
    }
    // node有右子节点但是没有左子节点
    else if (node->rchild && !node->lchild){
        transplant(node, node->rchild);     // 右子节点剪切到node位置
    }
    // node有左子节点又有右子节点
    else{
        auto next_node = successor(node);   // 节点node的后继节点
        // next_node不是node的右子节点(但一定存在与右子树中),那么转换为右子节点的情形
        if (next_node != node->rchild){
            transplant(next_node, next_node->rchild);   // 将后继的右子剪切到后继位置
            next_node->rchild = node->rchild;
            node->rchild->parent = next_node;
            node->rchild = next_node;
        }
        // node的后继就是node的右子节点
        transplant(node, node->rchild);    
        next_node->lchild = node->lchild;
        node->lchild->parent = next_node;
    }
}
// transplant: 二叉搜索树的剪切操作
/*
 * \parameter node1: 用一棵以node2为根的子树替换一棵以node1为根的子树;
 * \parameter node2: 用一棵以node2为根的子树替换一棵以node2为根的子树;
 * \return void.
 *
 * 算法基本思想: 用一棵以node2为根的子树替换一棵以node1为根的子树时,节点node1的双亲就变成节点node2
 *               的双亲,并且最后node2成为node1的双亲相应的孩子.
*/
template<typename NodeType>
void BinarySearchTree<NodeType>::transplant(std::shared_ptr<NodeType> &node1, 
                                            std::shared_ptr<NodeType> &node2)
{
    if (!node1)
        throw std::invalid_argument("node is nullptr!!!");
    auto parent_ptr = node1->parent.lock();     // 获取父节点
    // node1是一个根节点
    if (!parent_ptr)
    root = node2;
    // node1是一个右孩子节点
    else if (node1->is_right_child())
        parent_ptr->rchild = node2;
    // node1是一个左孩子节点
    else if (node1->is_left_child())
        parent_ptr->lchild = node2;
    // node2不是一个空指针
    if (node2)
        node2->parent = parent_ptr;    
}
#endif
