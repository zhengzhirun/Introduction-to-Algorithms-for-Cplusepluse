/*************************************************************************
	> File Name: hash.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月22日 星期四 09时43分29秒
 ************************************************************************/

#ifndef _HASH_H
#define _HASH_H
#include <iostream>
// 散列表中存储的数据
template<typename key_type, typename value_type>
class Hash
{
public:
    typedef value_type ValueType;   // 指向的数据类型
    //**************************构造函数***********************************
    Hash() = default;   // 默认构造函数
    Hash(key_type v0, value_type v1): key(v0), value(v1) {  }
    ~Hash() = default;
    friend bool operator==(const Hash &hash1, const Hash &hash2)
    {
        if (hash1.key == hash2.key && hash1.value == hash2.value)
            return true;
        else
            return false;
    }
    //**************************公有成员函数*******************************
    std::size_t getIndex() const
    {
        std::size_t hashIndex = 0;
        for (auto x : key)
            hashIndex += x * 128;
        return hashIndex;
    }
    //**************************数据成员***********************************
    key_type key;   // hash table 键
    value_type value;   // hash table值
};

#endif
