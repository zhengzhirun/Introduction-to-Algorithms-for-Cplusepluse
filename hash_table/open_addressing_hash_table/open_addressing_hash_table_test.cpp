/*************************************************************************
	> File Name: open_addressing_hash_table_test.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月22日 星期四 10时15分33秒
 ************************************************************************/
#include <iostream>
#include <string>
#include "hash.h"
#include "open_addressing_hash_table.h"
typedef Hash<std::string, int> IHash;
typedef HashTable<Hash<std::string, int>> Hashtable;

void inserts_test()
{
    Hashtable hashTable;
    bool sign = hashTable.insert({"cat",1234});
    std::cout << "'cat, 1234'是否插入成功: " << sign << std::endl;
    sign = hashTable.insert({"cat",1234});
    std::cout << "再次插入'cat, 1234'是否插入成功: " << sign << std::endl;
    sign = hashTable.insert({"Cat",111});
    std::cout << "'Cat,111'是否插入成功: " << sign << std::endl;
    sign = hashTable.insert({"cat",123});  
    std::cout <<"'zhi,123'是否插入成功: " << sign << std::endl;
}

void search_test()
{
    Hashtable hashTable;
    hashTable.insert({"cat",1234});
    hashTable.insert({"Cat",111});
    hashTable.insert({"cat",123});
    hashTable.insert({"ss",987});

    bool sign = hashTable.search({"cat",1234});
    std::cout << "'cat, 1234'是否存在hash table中: " << sign << std::endl;
    
    sign = hashTable.search({"Cat", 111});
    std::cout << "'Cat,111'是否在hash table中: " << sign << std::endl;

    sign = hashTable.search({"cat", 123});
    std::cout << "'cat,123'是否在hash table中: " << sign << std::endl;

    sign = hashTable.search({"ss",987});
    std::cout << "'ss,987'是否在hash table中: " << sign << std::endl;

    sign = hashTable.search({"ZHH",110});
    std::cout << "'ZHH',110是否在hash table中: " << sign << std::endl;
}

void hash_delete_test()
{
    Hashtable hashTable;
    hashTable.insert({"cat",1234});
    hashTable.insert({"Cat",111});
    hashTable.insert({"cat",123});
    hashTable.insert({"ss",987});
    
    //hashTable.hash_clear();
    bool sign = hashTable.hash_delete({"cat", 1234});
    std::cout << "'cat, 1234'是否删除成功: " << sign << std::endl;
    std::cout << "'cat, 1234'是否还在hash table中: " 
              << hashTable.search({"cat",1234}) << std::endl;

    sign = hashTable.hash_delete({"Cat", 111});
    std::cout << "'Cat, 111'是否删除成功: " << sign << std::endl;
    std::cout << "'Cat, 111'是否还在hash table中: " 
              << hashTable.search({"Cat",111}) << std::endl;

    sign = hashTable.hash_delete({"cat", 123});
    std::cout << "'cat, 123'是否删除成功: " << sign << std::endl;
    std::cout << "'cat, 123'是否还在hash table中: " 
              << hashTable.search({"cat",123}) << std::endl;
    
    sign = hashTable.hash_delete({"ss", 987});
    std::cout << "'ss, 987'是否删除成功: " << sign << std::endl;
    std::cout << "'ss, 987'是否还在hash table中: " 
              << hashTable.search({"ss",987}) << std::endl;
}

int main()
{
    std::cout << "********hash table的insert测试********\n";
    inserts_test();
    std::cout << "********hash table的search测试*******\n";
    search_test();
    std::cout << "********hash table的hash_delete测试********\n";
    hash_delete_test();

    return 0;
}

