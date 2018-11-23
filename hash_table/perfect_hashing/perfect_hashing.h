/*************************************************************************
	> File Name: perfect_hashing.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月22日 星期四 16时20分45秒
 ************************************************************************/
#ifndef _PERFECT_HASHING_H
#define _PERFECT_HASHING_H
#include <vector>
#include <random>
// Function: 散列函数的系数
struct Function
{
    std::size_t a;  // 二级散列函数((a*k+b) mod p) mod m
    std::size_t b;
    std::size_t p;
    std::size_t m;
};
// 待使用的随机产生的散列函数的系数
std::default_random_engine e;
// HashTable: 完全散列  算法导论11.5
/*
 * 如果从全域散列函数类中随机选出散列函数h,将n个关键字存储在一个大小为m=n^2的散列表中
 * 那么表中出现冲突的概率小于1/2.
 *
 * 使用散列技术通常是个很好的选择,不仅是因为它有优异的平均情况性能,而且当关键字集合是静态的
 * 时候,散列技术也能提供出色的最坏情况性能.所谓静态,就是指一旦各关键字存入表中,关键字集合就不再
 * 改变.
 *
 * 完全散列方法,如果对该方法进行查找的时候,能在最坏情况下用O(1)次访存完成.
*/
template<typename HashedObj>
class HashTable
{
public:
    //**************************结构函数**********************************
    HashTable(std::size_t num = 2): size(0){hashData.resize(num); function.resize(num);}
    ~HashTable() = default;     // 析构函数
    //**************************成员函数**********************************
    bool initialization(const std::vector<HashedObj> &);    // hash table 初始化
    bool search(const HashedObj &);     // hash table 查询操作
    bool insert(const HashedObj &);     // hash table 插入操作
    bool hash_delete(const HashedObj &); // hash table 删除操作
private:
    //**************************数据成员**********************************
    std::vector<std::vector<HashedObj>> hashData;   // 散列表的数组
    std::size_t size;   // 散列表中存储数据的数量
    std::vector<Function> function;     // 散列函数的系数
    //***********************私有成员函数*********************************
    std::size_t hash(const HashedObj &); // 一级hash table的散列函数
    void random_hash(const std::vector<std::size_t> &);   // 二级hash table随机散列函数
    void random_hash(const std::size_t);    // 重载二级hash table随机散列函数
    std::size_t hash2(const HashedObj &);   // 二级hash table散列函数
};
// hash: 一级散列函数
template<typename HashedObj>
std::size_t HashTable<HashedObj>::hash(const HashedObj &hashed)
{
    std::size_t hashIndex = hashed.getIndex();
    hashIndex = ((3 * hashIndex + 42) % 101) % hashData.size();
    return hashIndex;
}
// random_hash: 二级随机散列函数
template<typename HashedObj>
void HashTable<HashedObj>::random_hash(const std::vector<std::size_t> &numbers)
{

    for (decltype(numbers.size()) i = 0; i != numbers.size(); ++i){
        if (numbers[i] == 1){
            function[i].a = 0;
            function[i].b = 0;
            function[i].p = e();
            function[i].m = numbers[i];
        }
        else{
            function[i].a = e();
            function[i].b = e();
            function[i].p = e();
            function[i].m = numbers[i];
        }
    }
}
// random_hash: 重载二级随机散列函数
template<typename HashedObj>
void HashTable<HashedObj>::random_hash(const std::size_t levelIndex)
{
    if (function[levelIndex].m == 1){
        function[levelIndex].a = 0;
        function[levelIndex].b = 0;
        function[levelIndex].p = e();
    }
    else{
        function[levelIndex].a = e();
        function[levelIndex].b = e();
        function[levelIndex].p = e();
    }
}
// hash2: 二级散列函数
template<typename HashedObj>
std::size_t HashTable<HashedObj>::hash2(const HashedObj &hashed)
{
    std::size_t levelIndex = hash(hashed);
    std::size_t index = ((function[levelIndex].a * hashed.getIndex() + function[levelIndex].b) 
                         % function[levelIndex].p) % (function[levelIndex].m * function[levelIndex].m);
    return index;
}
// initialization: hash table初始化
/*
 * \parameter vec: 待初始化的数据向量;
 * \return bool(返回是否初始化成功的标志).
*/
template<typename HashedObj>
bool HashTable<HashedObj>::initialization(const std::vector<HashedObj> &vec)
{
    size = vec.size();
    std::vector<std::size_t> numbers;   // 统计散列到同一个槽的数量
    numbers.resize(hashData.size());
    for (auto &i : vec)
        numbers[hash(i)] += 1;
    for (decltype(hashData.size()) i = 0; i != hashData.size(); ++i)
        hashData[i].resize(numbers[i] * numbers[i]);
    bool sign = false;  // 标志是否发生冲突
    random_hash(numbers); // 随机产生初始散列函数
    do{
        sign = false;
        for (decltype(vec.size()) i = 0; i < vec.size(); ++i){
            std::size_t levelIndex = hash(vec[i]);
            std::size_t index = hash2(vec[i]);
            HashedObj hashObj;
            if (hashData[levelIndex][index] == hashObj){
                hashData[levelIndex][index] = vec[i];
                sign = false;
            }
            else{
                sign = true;
                for (int row = 0; row != hashData.size(); ++row)
                    for (int col = 0; col != hashData[row].size(); ++col)
                        hashData[row][col] = hashObj;                        
                random_hash(levelIndex);    // 随机产生这一列的二级散列新的随机函数
                break;
            }
        }    
    }while(sign);
    return true;
}
// search: 完全散列的查询操作
/*
 * \parameter hashed: 待查询的元素;
 * \return bool(查询是否成功的标志).
 * 算法性能(O(1)).
*/
template<typename HashedObj>
bool HashTable<HashedObj>::search(const HashedObj &hashed)
{
    bool sign = false;
    std::size_t levelIndex = hash(hashed);
    std::size_t index = hash2(hashed);
    if (hashData[levelIndex][index] == hashed)
        sign = true;
    return sign;
}
// insert: 完全散列的插入操作
/*
 * \parameter hashed: 待插入的元素;
 * \return bool(返回是否插入成功).
 * 算法性能(O(1)).
 * 算法基本思想: 完全散列插入最大的问题就在于冲突的处理,由于插入元素造成冲突处理的成本比较高,
 * 这里我们假定当插入元素与其它元素发生碰撞以后就禁止插入此元素.
*/
template<typename HashedObj>
bool HashTable<HashedObj>::insert(const HashedObj &hashed)
{
    bool sign = false;
    std::size_t levelIndex = hash(hashed);
    if (function[levelIndex].m == 0){
        std::cerr << "发生碰撞!禁止插入!" << std::endl;
        sign = false;
        return sign;
    }
    std::size_t index = hash2(hashed);
    HashedObj hashObj;
    if (hashData[levelIndex][index] == hashObj){
        hashData[levelIndex][index] = hashed;
        sign = true;
        ++size;
    }
    else{
        std::cerr << "发生冲突!禁止插入!" << std::endl;
        sign = false;
    }
    return sign;
}
// hash_delete: 完全散列的删除操作
/*
 * \parameter hashed: 待删除的元素;
 * \return bool(删除此单元成功的标志).
 * 算法性能: O(1).
*/
template<typename HashedObj>
bool HashTable<HashedObj>::hash_delete(const HashedObj &hashed)
{
    bool sign = false;
    std::size_t levelIndex = hash(hashed);
    if (function[levelIndex].m == 0){
        std::cerr << "未找到要删除的元素!" << std::endl;
        return false;
    }
    std::size_t index = hash2(hashed);
    HashedObj hashObj;
    if (hashData[levelIndex][index] == hashed){
        hashData[levelIndex][index] = hashObj;
        sign = true;
        --size;
    }
    else{
        std::cerr << "未找到要删除的元素!" << std::endl;
        sign = false;
    }
    return sign;
}
#endif
