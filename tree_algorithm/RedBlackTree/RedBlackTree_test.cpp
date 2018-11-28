/*************************************************************************
	> File Name: RedBlackTree_test.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月26日 星期一 22时56分55秒
 ************************************************************************/

#include <iostream>
using std::cout;    using std::endl;
#include "RedBlackTree.h"
typedef RedBlackTree<RedBlackTreeNode<int>> IntTree;
typedef RedBlackTreeNode<int> Node;
IntTree normalTree;     // 标准红黑树
// setUp: 产生一棵新的红黑树(1:黑色; 0:红色)
/*
 *                               7<1>
 *                          //          \\
 *                         4<1>        13<1>
 *                      //      \\     //   \\
 *                     3<1>     6<1>  9<1> 17<0>
 *                   //                    //   \\ 
 *                  2<0>                 15<1>  18<1>    
 *                                                 \\
 *                                                20<0>
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
    for (std::size_t i = 0; i != 11; ++i)
        normalTree.insert(nodes[i]);
    cout << "********************插入操作测试(返回所有节点信息)********************\n";
    for (std::size_t i = 0; i != 11; ++i)
        cout << nodes[i]->to_string() << endl;
    cout << "***********************最小关键值元素测试*****************************\n";
    cout << normalTree.minimum(normalTree.root)->key << std::endl;
    cout << "***********************最大关键值元素测试*****************************\n";
    cout << normalTree.maximum(normalTree.root)->key << std::endl;
    cout << "***********************前驱节点测试***********************************\n";
    auto max = normalTree.maximum(normalTree.root);
    for (std::size_t i = 0; i != 11; ++i){
        cout << max->key << " ";
        max = normalTree.predecessor(max);
    }
    cout << endl;

    cout << "***********************后继节点测试***********************************\n";
    auto min = normalTree.minimum(normalTree.root);
    for (std::size_t i = 0; i != 11; ++i){
        cout << min->key << " ";
        min = normalTree.successor(min);
    }
    cout << endl;
    normalTree.remove(nodes[8]);
    //for (std::size_t i = 0; i != 11; ++i)
    //    cout << nodes[i]->to_string() << endl;
}
int main()
{
    setUp();
    return 0;
}

