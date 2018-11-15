/*************************************************************************
	> File Name: stack.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月13日 星期二 09时47分23秒
 ************************************************************************/

#ifndef _STACK_H
#define _STACK_H
#include <memory>
#include <vector>
#include <algorithm>
#include <cassert>
// Stack: 栈 算法导论10.1
/*
 * 在栈中,被删除的是最近插入的元素:栈的实现是一种后进先出的数据结构
 * 栈需要支持的操作:
 *      --empty(S): 检查栈是否为空;
 *      --push(S,x): 向栈中压入一个元素;
 *      --pop(S): 栈中弹出一个元素.
 */
template<typename T>
class Stack{
public:
    //*************************构造函数**************************
    Stack(): size(0) {data.resize(0);}
    explicit Stack(std::size_t reverse_size): size(0) {data.resize(reverse_size);}
    // 拷贝构造函数
    Stack(const Stack& stack)
    {
        size = stack.size;
        std::copy(stack.data.begin(), stack.data.begin() + stack.size, data.begin());
    }
    // 拷贝赋值运算符
    Stack& operator=(const Stack& stack)
    {
        size = stack.size;
        std::copy(stack.data.begin(), stack.data.begin() + stack.size, data.begin());
        return *this;   // 返回一个此对象的引用
    }
    // 析构函数
    ~Stack() = default;
    //*************************成员函数**************************
    // empty: 检查栈是否为空.
    bool empty()
    {
        assert(size >= 0);
        return size;
    }
    // push: 向栈中压入一个元素.
    /*
     * \parameter element: 待压入栈中元素的指针;
     * \return void.
     *
     * 压入过程: 
     *      --检查element是不是一个空指针,若空指针则终止程序;
     *      --一旦栈已满,则把栈的容量增加一倍(为防止特殊的情况,如size=0,此时将栈容量设置为栈长度一倍加2);
     *      --将element压入栈的末尾.
    */
    void push(std::shared_ptr<T> element)
    {
        if (!element) return;   // 参数指针为一个空指针
        if (size == data.size())    data.resize(size * 2 + 2);  // 扩容
        std::size_t index = size;
        ++size;     // 自增
        data[index] = element;
    }
    // pop: 栈中弹出一个元素.
    /*
     * 当栈为空的时候,弹出一个空指针.
     * 把栈中最头部的元素弹出.
    */
    std::shared_ptr<T> pop()
    {
        bool isempty = empty();
        if (!isempty)   return std::shared_ptr<T>();
        --size; // 自减
        if (size <= data.size() / 4)
            data.resize(size * 2 + 2);      // 内存管理
        return data[size];
    }
private:
    //*************************数据结构**************************
    std::vector<std::shared_ptr<T>> data;   // 栈的数据
    std::size_t size;   // 栈的大小
};
#endif
