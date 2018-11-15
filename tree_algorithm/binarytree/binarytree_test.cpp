/*************************************************************************
	> File Name: binarytree_test.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月14日 星期三 18时57分43秒
 ************************************************************************/

#include <iostream>
using std::cout;    using std::endl;
#include "binarytree.h"
#include <sstream>
#include "../binarytreeNode/binarytreeNode.h"
typedef BinaryTree<BinaryTreeNode<int>> IntBinaryTree;
typedef BinaryTreeNode<int> Node;
IntBinaryTree normalTree;   // 生成一棵标准二叉树
IntBinaryTree emptyTree;    // 空树
void SetUp()
{
    std::shared_ptr<Node> nodes[9];
    for (int i = 0; i < 9; ++i)
        nodes[i] = std::make_shared<Node>(Node(i));
    nodes[1]->parent = std::weak_ptr<Node>(nodes[0]);
    nodes[2]->parent = std::weak_ptr<Node>(nodes[0]);
    nodes[0]->lchild = nodes[1];
    nodes[0]->rchild = nodes[2];

    nodes[3]->parent = std::weak_ptr<Node>(nodes[1]);
    nodes[4]->parent = std::weak_ptr<Node>(nodes[1]);
    nodes[1]->lchild = nodes[3];
    nodes[1]->rchild = nodes[4];

    nodes[5]->parent = std::weak_ptr<Node>(nodes[2]);
    nodes[6]->parent = std::weak_ptr<Node>(nodes[2]);
    nodes[2]->lchild = nodes[5];
    nodes[2]->rchild = nodes[6];

    nodes[7]->parent = std::weak_ptr<Node>(nodes[3]);
    nodes[8]->parent = std::weak_ptr<Node>(nodes[3]);
    nodes[3]->lchild = nodes[7];
    nodes[3]->rchild = nodes[8];
    
    normalTree.root = nodes[0];
}
// 测试二叉树的前序遍历
void preorder_walk_test()
{
    cout << "对标准二叉树前序遍历测试:\n";
    std::ostringstream os;
    auto do_work = [&os](int val){os << val << ";";};
    preorder_walk(normalTree.root, do_work);
    cout << "前序遍历的结果: " << os.str() << endl;

    cout << "对空二叉树前序遍历测试:\n";
    std::ostringstream os1;
    auto do_work1 = [&os1](int val){os1 << val << ";";};
    preorder_walk(emptyTree.root, do_work1);
    cout << "前序遍历的结果: " << os1.str() << endl;
}
// 测试二叉树的中序遍历
void inorder_walk_test()
{
    cout << "对标准二叉树中序遍历测试:\n";
    std::ostringstream os;
    auto do_work = [&os](int val){os << val << ";";};
    inorder_walk(normalTree.root, do_work);
    cout << "中序遍历的结果: " << os.str() << endl;

    cout << "对空二叉树前序遍历测试:\n";
    std::ostringstream os1;
    auto do_work1 = [&os1](int val){os1 << val << ";";};
    inorder_walk(emptyTree.root, do_work1);
    cout << "中序遍历的结果: " << os1.str() << endl;
}
// 测试二叉树的后序遍历
void postorder_walk_test()
{
    cout << "对标准二叉树后序遍历测试:\n";
    std::ostringstream os;
    auto do_work = [&os](int val){os << val << ";";};
    postorder_walk(normalTree.root, do_work);
    cout << "后序遍历的结果: " << os.str() << endl;

    cout << "对空二叉树后序遍历测试:\n";
    std::ostringstream os1;
    auto do_work1 = [&os1](int val){os1 << val << ";";};
    postorder_walk(emptyTree.root, do_work1);
    cout << "后序遍历的结果: " << os1.str() << endl;
}
int main()
{

    SetUp();
    preorder_walk_test();
    inorder_walk_test();
    postorder_walk_test();
    return 0;
}

