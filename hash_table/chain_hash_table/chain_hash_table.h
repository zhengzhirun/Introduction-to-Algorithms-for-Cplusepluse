/*************************************************************************
	> File Name: chain_hash_table.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月18日 星期日 20时54分22秒
 ************************************************************************/

#ifndef _CHAIN_HASH_TABLE_H
#define _CHAIN_HASH_TABLE_H
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
// HashTable: 分离链接法(双向链表结构)处理冲突情况的散列表. 算法导论11.2 11.3
/*
 * 简而言之,散列就是一种用以常数平均时间执行插入,删除的技术.但是元素间排序将不会
 * 得到支持.可以把散列理解为介于链表与二叉树之间的数据结构.
 *
 * 散列最主要的问题就是确定散列函数,以解决冲突问题.(当两个关键字散列到一个值的时候产生冲突).
 *
 * 解决冲突的方法最简单的有两种: 分离链接法和开放定址法.
*/
template<typename HashedObj>
class HashTable
{
public:
    //typedef typename HashedObj::ValueType valueType;  
    //***************************构造函数*********************************
    explicit HashTable(std::size_t size = 101): currentSize(0) {theLists.resize(size);}
    ~HashTable()=default;
    //***************************成员函数*********************************
    bool contains(const HashedObj &x) const; // 向散列表中查询一个元素
    void makeEmpty(); 	// 清空散列表
    bool insert(const HashedObj &x); 	// 向散列表中插入一个元素
    bool remove(const HashedObj &x); 	// 向散列表中删除一个元素
private:
    //***************************数据结构*********************************
    std::vector<std::list<HashedObj>> theLists;     // 链表的数组
    std::size_t currentSize;        // 哈希数组大小
    //***************************私有成员函数*****************************
    void rehash();
    std::size_t myhash(const HashedObj &x) const;
};
//***************************私有成员函数*********************************
// rehash: 重新建立hash表.
template<typename HashedObj>
void HashTable<HashedObj>::rehash()
{
    theLists.resize(0);
    currentSize = 0;
}
// myhash: 将HashedObj的值转换为数组的下标
/*
 * \parameter x: 待转换的元素;
 * \return 数组下标.
*/
template<typename HashedObj>
std::size_t HashTable<HashedObj>::myhash(const HashedObj &x) const
{
    std::size_t hashIndex = x.getIndex();
    // 除法散列法
    /*
     * 关于除法散列函数: 选取m(theLists.size())的值特别重要,一个不太接近2的整数幂的素数,常常是
     * m的一个较好的选择.
    */
    
    //hashIndex = hashIndex % theLists.size();

    // 乘法散列法
    /*
     * 关于乘法散列函数: 包含两个步骤:
     *      --第一步,用关键字k乘上常数A(0<A<1),提取kA的小数部分;
     *      --第二步,用m乘以这个值再向下取整.
     * 乘法散列法的一个优点是对m的选择不是特别关键,一般选择它为2的某个幂次方;A的取值为(sqrt(5)-1)/2是一个理想的值.
    */
    double indexValue = (hashIndex * (std::sqrt(5)-1) / 2);
    indexValue = indexValue - static_cast<int>(indexValue);
    hashIndex = std::floor(101 * indexValue);
    
    // 全域散列法
    /*
     * 任何一个特定的散列函数都会出现将n个关键字全部散列到同一个槽中,使得品均的检索时间为O(N),这个就是令人恐怖的最坏的情况.
     * 唯一有效的改进方法就是随机地选择散列函数,使之独立于要存储的关键字,这种方法称为全域散列.不管选择了怎样的关键字,其品均
     * 性能都比较好.
     *
     * 全域散列法在执行的开始,就从一组精心设计的函数中,随机选择一个作为散列函数.就像在快速排序中一样,随机化保证了没有哪一种
     * 输入会始终导致最坏的情况性能.
    */
    return hashIndex;
}
//***************************成员函数*************************************
// contains: 检查成员是否被包含在hash table中.
/*
 * \parameter x: 待检查的元素;
 * \return 返回这个元素是否存在于hash table中.
*/
template<typename HashedObj>
bool HashTable<HashedObj>::contains(const HashedObj &x) const
{
    auto &whichList = theLists[myhash(x)];
    return std::find(whichList.begin(), whichList.end(), x) != whichList.end();
}
// makeEmpty: 把hash table置空.
/*
 * \return void.
 * 将hash table置空以后.
*/
template<typename HashedObj>
void HashTable<HashedObj>::makeEmpty()
{
    for (auto &thisList : theLists)
        thisList.clear();
}
// insert: 将一个元素插入到hash table 中
/*
 * \parameter x: 一个待插入的元素;
 * \return 插入是否成功的标志.
 * 当元素在hash table中插入不成功,返回false;
 * 当元素不在hash table中,插入到链表的最尾端,返回true.
*/
template<typename HashedObj>
bool HashTable<HashedObj>::insert(const HashedObj &x)
{
    auto &whichList = theLists[myhash(x)];
    if (std::find(whichList.begin(), whichList.end(), x) != whichList.end() &&
        whichList.begin() != whichList.end())
        return false;
    whichList.push_back(x);
    ++currentSize;
    return true;
}
// remove: 将一个元素从hash table中删除.
/*
 * \parameter x: 一个待删除的元素;
 * \return 返回是否删除成功的标志.
 * 当元素在hash table中删除成功,返回true;
 * 当元素不在hash table中,删除不成功,返回false.
*/
template<typename HashedObj>
bool HashTable<HashedObj>::remove(const HashedObj &x)
{
    auto &whichList = theLists[myhash(x)];
    auto iter = std::find(whichList.begin(), whichList.end(), x);
    if (iter == whichList.end())
        return false;
    whichList.erase(iter);
    --currentSize;
    return true;
}
#endif
