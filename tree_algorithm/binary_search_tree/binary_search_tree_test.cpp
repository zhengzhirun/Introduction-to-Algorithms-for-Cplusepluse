/*************************************************************************
	> File Name: binary_search_tree_test.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月24日 星期六 10时30分31秒
 ************************************************************************/

#include <iostream>
using std::cout;    using std::endl;
#include <memory>
#include "../binarytreeNode/binarytreeNode.h"
#include "binary_search_tree.h"
typedef BinarySearchTree<BinaryTreeNode<int>> IntBinarySearchTree;
typedef BinaryTreeNode<int> Node;
typedef Node::KeyType KeyType;
IntBinarySearchTree normalTree;     // 生成一棵标准的二叉搜索树
IntBinarySearchTree binarySearchTree;      // 生成一棵空的二叉树
// setUp: 产生一棵新的二叉搜索树
/*
 *                                 15
 *                          //          \\
 *                          6            18
 *                      //      \\      // \\
 *                      3        7      17  20
 *                   //   \\      \\
 *                   2     4       13
 *                                 //
 *                                 9
*/
bool setUp()
{   
    std::shared_ptr<Node> nodes[11];
    nodes[0] = std::make_shared<Node>(15);
    nodes[1] = std::make_shared<Node>(6);
    nodes[2] = std::make_shared<Node>(7);
    nodes[3] = std::make_shared<Node>(3);
    nodes[4] = std::make_shared<Node>(4);
    nodes[5] = std::make_shared<Node>(2);
    nodes[6] = std::make_shared<Node>(13);
    nodes[7] = std::make_shared<Node>(9);
    nodes[8] = std::make_shared<Node>(18);
    nodes[9] = std::make_shared<Node>(17);
    nodes[10] = std::make_shared<Node>(20);
    bool sign = true;
    for (std::size_t i = 0; i != 11; ++i){
        bool sign1 = normalTree.insert(nodes[i]);
        if (!sign1)
            sign = sign1;
    }
    cout << "*******************二叉树后继节点测试*************************\n";
    for (int i = 0; i != 11; ++i){
        auto value = normalTree.successor(nodes[i]);
        if (value)
            cout << "节点" << nodes[i]->key << "的后继节点为: " << value->key << endl; 
    }
    cout << "*******************利用后继操作排序***************************\n";
    auto min_ptr = normalTree.minimum(normalTree.root);
    while (min_ptr){
        cout << min_ptr->key << " ";
        min_ptr = normalTree.successor(min_ptr);
    }
    cout << endl;
    cout << "*******************二叉树前驱节点测试*************************\n";
    for (int i = 0; i != 11; ++i){
        auto value = normalTree.predecessor(nodes[i]);
        if (value)
            cout << "节点" << nodes[i]->key << "的后继节点为: " << value->key << endl;
    }
    cout << "*******************利用前驱操作排序***************************\n";
    auto max_ptr = normalTree.maximum(normalTree.root);
    while (max_ptr){
        cout << max_ptr->key << " ";
        max_ptr = normalTree.predecessor(max_ptr);
    }
    cout << endl;
    cout << "*******************新建二叉搜索树*****************************\n";
    return sign;
}

bool action(KeyType key) 
{
    std::cout << key << " ";
}

void preorderWalk_test()
{
    cout << "二叉树的前序遍历:\n";
    normalTree.preorderWalk(normalTree.root, action);
    cout << "\n二叉树的中序遍历:\n";
    normalTree.inorderWalk(normalTree.root, action);
    cout << "\n二叉树的后序遍历:\n";
    normalTree.postorderWalk(normalTree.root, action);
}

void minimum_test()
{
    cout << "二叉搜索树中的最小值为: \n";
    cout << normalTree.minimum(normalTree.root)->key << endl;
}

void maximum_test()
{
    cout << "二叉搜索树中的最大值为: \n";
    cout << normalTree.maximum(normalTree.root)->key << endl;
}

void search_test()
{
    Node node(20);
    auto value = normalTree.search(node);
    cout << "二叉搜索树中是否包含元素20: "
        << value->key << endl;
}

void remove_test()
{
    std::shared_ptr<Node> nodes[11];
    nodes[0] = std::make_shared<Node>(15);
    nodes[1] = std::make_shared<Node>(6);
    nodes[2] = std::make_shared<Node>(7);
    nodes[3] = std::make_shared<Node>(3);
    nodes[4] = std::make_shared<Node>(4);
    nodes[5] = std::make_shared<Node>(2);
    nodes[6] = std::make_shared<Node>(13);
    nodes[7] = std::make_shared<Node>(9);
    nodes[8] = std::make_shared<Node>(18);
    nodes[9] = std::make_shared<Node>(17);
    nodes[10] = std::make_shared<Node>(20);
    for (std::size_t i = 0; i != 11; ++i)
        binarySearchTree.insert(nodes[i]);
    // 删除叶子节点
    //binarySearchTree.remove(nodes[0]);
    cout << "二叉搜索树按照从小到达的顺序依次为:\n";
    auto min = binarySearchTree.minimum(binarySearchTree.root);
    for (int i = 0; i != 11; ++i){
        cout << min->key << " ";
        min = binarySearchTree.successor(min);
    }
    std::cout << endl;

    // 删除操作
    for (int i = 0; i != 11; ++i){
        cout << "删除" << nodes[i]->key << "后，排序:\n";
        binarySearchTree.remove(nodes[i]);
        min = binarySearchTree.minimum(binarySearchTree.root);
        for (int j = 0; j != (11-i-1); ++j){
            cout << min->key << " ";
            min = binarySearchTree.successor(min);
        }
        cout << endl;
    }
}
int main()
{
    cout << "新建二叉搜索树是否成功: " << setUp() << endl;
    cout << "*******************二叉树的遍历测试***************************\n";
    preorderWalk_test();
    cout << "\n";
    cout << "*****************二叉树的最小关键值元素***********************\n";
    minimum_test();
    cout << "*****************二叉树的最大关键值元素***********************\n";
    maximum_test();
    cout << "*****************二叉树的查询操作测试*************************\n";
    search_test();
    cout << "*****************二叉树的删除操作测试*************************\n";
    remove_test();
    return 0;
}

