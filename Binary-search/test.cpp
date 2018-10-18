/*************************************************************************
	> File Name: test.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年10月18日 星期四 13时34分26秒
 ************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include "binarySearch.h"

template <typename T>
void readData(const std::string filename, std::vector<T> &vec)
{
    std::ifstream in(filename);
    T value;
    while (in >> value)
        vec.push_back(value);
}

int main(void)
{
    std::vector<int> data;
    readData("testData", data);
    sort(data.begin(), data.end());
    int value = 57;
    int sign = binarySearch(data, value);
    std::cout << "****************************************************" << std::endl;
    for (decltype(data.size()) i = 0; i != data.size(); i++)
        std::cout << i << "\t" << data[i] << "\n";
    std::cout << "****************************************************" << std::endl;
    std::cout << value << "在顺序数组的第" << sign << std::endl;

    return 0;
}
