/*************************************************************************
	> File Name: chain_hash_table_test.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月21日 星期三 17时13分53秒
 ************************************************************************/
#include <iostream>
#include <string>
#include "hash.h"
#include "chain_hash_table.h"
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
    hashTable.insert({"cat",123});  
    std::cout <<"'zhi,123'是否插入成功: " << sign << std::endl;
}

void contains_test()
{
    Hashtable hashTable;
    hashTable.insert({"cat",1234});
    hashTable.insert({"Cat",111});
    hashTable.insert({"cat",123});
    hashTable.insert({"ss",987});

    bool sign = hashTable.contains({"cat",1234});
    std::cout << "'cat, 1234'是否存在hash table中: " << sign << std::endl;
    
    sign = hashTable.contains({"Cat", 111});
    std::cout << "'Cat,111'是否在hash table中: " << sign << std::endl;

    sign = hashTable.contains({"cat", 123});
    std::cout << "'cat,123'是否在hash table中: " << sign << std::endl;

    sign = hashTable.contains({"ss",987});
    std::cout << "'ss,987'是否在hash table中: " << sign << std::endl;

    sign = hashTable.contains({"ZHH",110});
    std::cout << "'ZHH',110是否在hash table中: " << sign << std::endl;
}

void remove_test()
{
    Hashtable hashTable;
    hashTable.insert({"cat",1234});
    hashTable.insert({"Cat",111});
    hashTable.insert({"cat",123});
    hashTable.insert({"ss",987});
    
    //hashTable.makeEmpty();
    bool sign = hashTable.remove({"cat", 1234});
    std::cout << "'cat, 1234'是否删除成功: " << sign << std::endl;
    std::cout << "'cat, 1234'是否还在hash table中: " 
              << hashTable.contains({"cat",1234}) << std::endl;

    sign = hashTable.remove({"Cat", 111});
    std::cout << "'Cat, 111'是否删除成功: " << sign << std::endl;
    std::cout << "'Cat, 111'是否还在hash table中: " 
              << hashTable.contains({"Cat",111}) << std::endl;

    sign = hashTable.remove({"cat", 123});
    std::cout << "'cat, 123'是否删除成功: " << sign << std::endl;
    std::cout << "'cat, 123'是否还在hash table中: " 
              << hashTable.contains({"cat",123}) << std::endl;
    
    sign = hashTable.remove({"ss", 987});
    std::cout << "'ss, 987'是否删除成功: " << sign << std::endl;
    std::cout << "'ss, 987'是否还在hash table中: " 
              << hashTable.contains({"ss",987}) << std::endl;
}
int main()
{
    std::cout << "********hash table的insert测试********\n";
    inserts_test();
    std::cout << "********hash table的contains测试*******\n";
    contains_test();
    std::cout << "********hash table的remove测试********\n";
    remove_test();

    return 0;
}


