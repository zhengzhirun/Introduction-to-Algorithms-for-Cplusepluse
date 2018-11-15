/*************************************************************************
	> File Name: queue.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月13日 星期二 14时11分15秒
 ************************************************************************/

#ifndef _QUEUE_H
#define _QUEUE_H
#include <iostream>
#include <vector>
#include <memory>
// Queue: 队列 算法导论10.1
/*
 * 在队列中,被删除的是最先插入的元素,队列的实现是一种先进先出的数据结构.
 * 队列需要支持的操作:
 *      --enQueue(S,x): 向队列中插入一个新元素x;
 *      --deQueue(S): 队列中弹出一个元素;
*/
template<typename T>
class Queue
{
public:
    //****************************构造函数*******************************
    Queue(std::size_t numbers): head(0), tail(0) {data.resize(numbers);}
    Queue(): head(0), tail(0) {data.resize(20);}
    ~Queue() = default;
    //****************************成员函数*******************************
    // enQueue: 向队列中插入一个元素
    /*
     * \parameter num: 指向入队元素的指针;
     * \return void.
     * 当head=tail+1时队列是满的,禁止插入新元素.
    */
    void enQueue(std::shared_ptr<T> num)
    {
        // 检查上溢
        if (head % data.size() == (tail + 1) % data.size()){
            std::cerr << "队列已满,禁止插入新元素" << endl;
            return;
        }
        data[tail] = num;
        ++tail;     // tail自增
        if (tail >= data.size())
            tail %= data.size();
    }
    // deQueue: 出队
    /*
     * \retrun 返回出队的元素.
     * 当head=tail时队列为空,禁止出队.
    */
    std::shared_ptr<T> deQueue()
    {
        // 检查下溢
        if (head % data.size() == tail % data.size()){
            std::cerr << "队列为空,禁止出队" << endl;
            return std::shared_ptr<T>();
        }
        std::shared_ptr<T> temp = data[head];
        ++head;     // head自增
        head %= data.size();
        return temp;
    }
    // empty: 检查队列是否为空
    /*
     * \return bool: 当队列为空返回false,队列不为空返回true.
     * 当head=tail时队列为空.
    */
    bool empty()
    {
        bool isEmpty = true;
        if (head % data.size() == tail % data.size())
        isEmpty = false;
        return isEmpty;
    }
private:
    //****************************数据结构*******************************
    std::vector<std::shared_ptr<T>> data;       // 队列的数据
    std::size_t head;        // 队头
    std::size_t tail;        // 队尾
};
#endif
