/*************************************************************************
	> File Name: binarytreeNode_test.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月14日 星期三 16时09分50秒
 ************************************************************************/

#include <iostream>
using std::cout;    using std::endl;
#include "binarytreeNode.h"
void Test()
{
    BinaryTreeNode<int> intNode(14);
    cout << "key " << intNode.key << endl;   
    cout << intNode.to_string() << endl;
    cout << intNode.to_xml() << endl;
    cout << "is_left_child " << intNode.is_left_child() << endl;
    cout << "is_right_child " << intNode.is_right_child() << endl;
}

void setup()
{
    typedef BinaryTreeNode<int> Node;
    auto root_node = std::make_shared<Node>(0);
    root_node->lchild = std::make_shared<Node>(1);
    root_node->rchild = std::make_shared<Node>(2);
    root_node->lchild->parent = root_node;
    root_node->rchild->parent = root_node;

    cout << "key " << root_node->key << endl;
    cout << root_node->to_string() << endl;
    cout << root_node->to_xml() << endl;

    cout << "is_left_child " << root_node->is_left_child() << endl;
    cout << "is_right_child " << root_node->is_right_child() << endl;

    cout << "is_left_child " << root_node->lchild->is_left_child() << endl;
    cout << "is_right_child " << root_node->rchild->is_right_child() << endl;

}

int main()
{
    Test();

    setup();

    return 0;
}
