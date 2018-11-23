/*************************************************************************
	> File Name: perfect_hashing_test.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月22日 星期四 21时45分14秒
 ************************************************************************/

#include <iostream>
using std::cout;    using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include "perfect_hashing.h"
#include "hash.h"
typedef Hash<string, int> HashData;
typedef HashTable<Hash<string, int>> PerHash;

HashData h1("zhi",123);
HashData h2("lu",123);
HashData h3("llli",123);
HashData h4("whhhi",123);
HashData h5("ki",123);
HashData h6("zi",123);
void initial(PerHash &hash)
{
    vector<HashData> vec;
    vec.push_back(h1);
    vec.push_back(h2);
    vec.push_back(h3);
    vec.push_back(h4);
    vec.push_back(h5);
    vec.push_back(h6);
    cout << "完全散列是否初始化成功: " << hash.initialization(vec) << endl;
}

int main()
{
    
    PerHash hash;
    initial(hash);
    cout << "*************************************************\n";
    bool sign = hash.search({"zhi",123});
    cout << "元素'zhi,123'是否在完全散列中: " << sign << endl;
    sign = hash.hash_delete(h1);
    cout << "元素'zhi,123'是否删除成功: " << sign << endl;
    sign =  hash.search(h1);
    cout << "元素'zhi,123'是否在完全散列中: " << sign << endl;
    
    cout << "*************************************************\n";
    sign = hash.search(h2);
    cout << "元素'liu,123'是否在完全散列中: " << sign << endl;
    sign = hash.hash_delete(h2);
    cout << "元素'liu,123'是否删除成功: " << sign << endl;
    sign = hash.search(h2);
    cout << "元素'liu, 123'是否在完全散列中: " << sign << endl;

    cout << "*************************************************\n";
    sign = hash.search(h3);
    cout << "元素'li,123'是否在完全散列中: " << sign << endl;
    sign = hash.hash_delete(h3);
    cout << "元素'li,123'是否删除成功: " << sign << endl;
    sign = hash.search(h3);
    cout << "元素'li, 123'是否在完全散列中: " << sign << endl;
    
    cout << "*************************************************\n";
    sign = hash.search(h4);
    cout << "元素'whai,123'是否在完全散列中: " << sign << endl;
    sign = hash.hash_delete(h4);
    cout << "元素'whai,123'是否删除成功: " << sign << endl;
    sign = hash.search(h4);
    cout << "元素'whai, 123'是否在完全散列中: " << sign << endl;
    
    cout << "*************************************************\n";
    sign = hash.search(h5);
    cout << "元素'ki,123'是否在完全散列中: " << sign << endl;
    sign = hash.hash_delete(h5);
    cout << "元素'ki,123'是否删除成功: " << sign << endl;
    sign = hash.search(h5);
    cout << "元素'ki, 123'是否在完全散列中: " << sign << endl;
    
    cout << "*************************************************\n";
    sign = hash.search(h6);
    cout << "元素'zi,123'是否在完全散列中: " << sign << endl;
    sign = hash.hash_delete(h6);
    cout << "元素'zi,123'是否删除成功: " << sign << endl;
    sign = hash.search(h6);
    cout << "元素'zi, 123'是否在完全散列中: " << sign << endl;
    
    cout << "**********************插入测试*******************\n";
    sign = hash.insert({"hello",12345});
    cout << "插入'hello,12345'是否成功: " << sign << endl;
    return 0;
}

