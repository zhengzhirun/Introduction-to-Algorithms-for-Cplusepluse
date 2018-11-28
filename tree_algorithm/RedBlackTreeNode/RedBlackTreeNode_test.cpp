/*************************************************************************
	> File Name: RedBlackTreeNode_test.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月26日 星期一 18时57分50秒
 ************************************************************************/

#include <iostream>
using std::cout;    using std::endl;
#include "RedBlackTreeNode.h"

void Test()
{
    RedBlackTreeNode<int> intNode(14);
    cout << "key: " << intNode.key << endl;
    cout << "color: " << intNode.color << endl;

    cout << intNode.to_string() << endl;
    cout << intNode.to_xml() << endl;

    cout << "is_left_child " << intNode.is_left_child() << endl;
    cout << "is_right_child " << intNode.is_right_child() << endl;
}

void setUp()
{
    typedef RedBlackTreeNode<int> Node;
    auto root = std::make_shared<Node>(0);
    root->lchild = std::make_shared<Node>(1);
    root->rchild = std::make_shared<Node>(2);
    root->lchild->parent = root;
    root->rchild->parent = root;
    cout << "key " << root->key << endl;
    cout << "color " << root->color << endl;
    cout << root->to_string() << endl;
    cout << root->to_xml() << endl;

    cout << "is_left_child " << root->is_left_child() << endl;
    cout << "is_right_child " << root->is_right_child() << endl;

    cout << "is_left_child " << root->lchild->is_left_child() << endl;
    cout << "is_right_child " << root->rchild->is_right_child() << endl;
}
int main()
{
    Test();
    setUp();

    return 0;
}
