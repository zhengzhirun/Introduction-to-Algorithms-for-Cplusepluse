/*************************************************************************
	> File Name: open_addressing_hash_table.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月22日 星期四 08时40分05秒
 ************************************************************************/

#ifndef _OPEN_ADDRESSING_HASH_TABLE_H
#define _OPEN_ADDRESSING_HASH_TABLE_H
#include <vector>
// HashTable: 开放寻址法实现散列 算法导论11.4
/*
 * 开放寻址法的好处就在于它不用指针,而是计算出要存取的槽序列.于是,不用存储
 * 指针而节省的空间,使得可以用同样的空间来提供更多的槽,潜在的减少了冲突,提高了
 * 检索速度.
*/
template<typename HashedObj>
class HashTable
{
public:
    //***************************枚举类型*********************************
    enum ELE_STATUS{
        EMPTY = 0,      // 空的
        DELETE = 1,     // 被删除的
        FULL = 2,       // 有元素的
    };
    //***************************构造函数*********************************
    // 构造函数
    HashTable(std::size_t num = 101): size(0){hashData.resize(num); status.resize(num);}
    ~HashTable() = default;     // 析构函数
    //***************************成员函数*********************************
    bool insert(const HashedObj &);     // 向散列表中插入一个元素
    bool search(const HashedObj &);     // 向散列表中查找一个元素
    bool hash_delete(const HashedObj &);    // 向散列表中删除一个元素
    void hash_clear();  // 清空散列表
private:
    //***************************数据成员*********************************
    std::vector<HashedObj> hashData;    // 散列表的数组
    std::size_t size;   // 散列表中存储数据的数量
    std::vector<ELE_STATUS> status;     // 用于存放各个位置的状态信息
    //*************************私有成员函数*******************************
    std::size_t hash(const HashedObj &);  // 辅助散列函数(除法散列函数)
    std::size_t hash2(const HashedObj &);   // 双重散列函数的辅助函数
    std::size_t linear_probing(const HashedObj &, std::size_t);    // 线性探查
    std::size_t quadratic_probing(const HashedObj &, std::size_t);  // 二次探查
    std::size_t double_hashing(const HashedObj &, std::size_t);     // 双重散列
};
// hash: 辅助散列函数(除法散列函数)
template<typename HashedObj>
std::size_t HashTable<HashedObj>::hash(const HashedObj &hashed)
{
    std::size_t index = hashed.getIndex();
    index = index % hashData.size();
    return index;
}
// hash2: 双重散列函数的辅助函数
template<typename HashedObj>
std::size_t HashTable<HashedObj>::hash2(const HashedObj &hashed)
{
    std::size_t index = hashed.getIndex();
    index = index % (hashData.size() - 1) + 1;
    return index;
}
// linear_probing: 线性探查
/*
 * \parameter hashed: hash table存储的数据类型;
 * \parameter offset: 线性探查公式中的i;
 * \return 返回线性探查结果的下标.
 * 算法思想: h(k,i) = (h(k) + i) mod m, i = 0,1,2,...,m-1
 * 线性探查方法比较容易实现,但它存在着一个问题,称为一次聚集. 随着连续被占用的槽不断增加,平均
 * 查找时间也随之不断增加.群集现象很容易出现,这是因为当一个空槽前有i个满的槽时,该空槽为下一个被
 * 占用的概率为(i+1)/m.连续被占用的槽就会变得越来越长,因而平均查找时间也会越来越大.
*/
template<typename HashedObj>
std::size_t HashTable<HashedObj>::linear_probing(const HashedObj &hashed, std::size_t offset)
{
    return (hash(hashed) + offset) % hashData.size();
}
// quadratic_probing: 二次探查
/*
 * \parameter hashed: hash table存储的数据类型;
 * \parameter offset: 二次查探函数中的i;
 * \return 返回二次查探结果的下标.
 * 算法思想: h(k,i) = (h(k) + c1*i + c2*i*i) mod m, i = 0,1,2,...,m-1
 * 二次查探的性质比线性查探的性质好很多,但是h(k1,0) = h(k2,0)蕴含着h(k1,i) = h(k2,i).
 * 这一性质可导致一种轻度的群集,称为二次群集.
*/
template<typename HashedObj>
std::size_t HashTable<HashedObj>::quadratic_probing(const HashedObj &hashed, std::size_t offset)
{
    return (hash(hashed) + offset + offset * offset) % hashData.size();
}
// double_hashing: 双重散列
/*
 * \parameter hashed: hash table存储的数据类型;
 * \parameter offset: 双重查探函数中的i;
 * \return 返回双重查探结果的下标.
 * 算法思想: h(k,i) = (h1(k) + i*h2(k)) mod m; i = 0,1,2,3,...,m-1.
 * 双重散列是用于开放寻址的最好方法之一,因为它所产生的排列具有随机选择排序的许多特征.
 *
 * 为了能查找整个散列表,值h2(k)必须要与表的大小m互素.有一种简便的方法确保这个条件成立,就是
 * 取m为2的幂,并设计一个总产生奇数的h2.
 * 另一种方法是取m为素数,并设计一个总返回较m小的正整数的函数h2.
 *   --例如,我们可以取m为素数,并取h1(k) = k mod m, h2(k) = 1 + (k mod m')
 *     其中m'略小于m(比如,m-1).
*/
template<typename HashedObj>
std::size_t HashTable<HashedObj>::double_hashing(const HashedObj &hashed, std::size_t offset)
{
    std::size_t index0 = hash(hashed);
    std::size_t index1 = hash2(hashed);
    return (index0 + offset * index1) % hashData.size();
}

//*******************************函数接口*********************************
// insert: 插入操作
/*
 * \parameter hash: 待插入的元素;
 * \return 返回插入是否成功的标志.
*/
template<typename HashedObj>
bool HashTable<HashedObj>::insert(const HashedObj &hash)
{
    if (size >= hashData.size()){
        std::cerr << "hash table overflow!" << std::endl;;
        return false;
    }
    std::size_t i = 0;
    while (i != hashData.size()){
        //std::size_t index = linear_probing(hash, i);
        //std::size_t index = quadratic_probing(hash, i);
        std::size_t index = double_hashing(hash, i);
        if (status[index] != FULL){
            hashData[index] = hash;
            status[index] = FULL;
            ++size;
            return true;
        }
        ++i;
    }
    std::cerr << "hash table overflow!" << std::endl;
    return false;
}
// search: 查询操作
/*
 * \parameter hashed: 待查找的元素;
 * \return 返回查找是否成功的标志.
*/
template<typename HashedObj>
bool HashTable<HashedObj>::search(const HashedObj &hashed)
{
    std::size_t i = 0;
    while (i != hashData.size()){
        //std::size_t index = linear_probing(hashed, i);
        //std::size_t index = quadratic_probing(hashed, i);
        std::size_t index = double_hashing(hashed, i);
        if (status[index] == EMPTY)
            return false;
        else if (status[index] == FULL){
            if (hashData[index] == hashed)
                return true;
        }
        ++i;
    }
    return false;
}
// hash_delete: 删除操作
/*
 * \parameter hashed: 待删除的元素;
 * \return 删除是否成功的标志.
*/
template<typename HashedObj>
bool HashTable<HashedObj>::hash_delete(const HashedObj &hashed)
{
    std::size_t i = 0;
    while (i != hashData.size()){
        //std::size_t index = linear_probing(hashed, i);
        //std::size_t index = quadratic_probing(hashed, i);
        std:;size_t index = double_hashing(hashed, i);
        if (status[index] == EMPTY)
            return false;
        else if (status[index] == FULL){
            if (hashData[index] == hashed){
                status[index] = DELETE;
                return true;
                --size;
            }
        }
        ++i;
    }
    return false;
}
// hash_clear: 清空散列表
/*
 * 只需对状态数组修改就行.
*/
template<typename HashedObj>
void HashTable<HashedObj>::hash_clear()
{
    size = 0;
    for (auto &i : status)
        i = EMPTY;
}
#endif
