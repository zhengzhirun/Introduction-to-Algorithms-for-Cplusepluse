/*************************************************************************
	> File Name: Test.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年10月17日 星期三 20时15分37秒
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <time.h>
#include "maxSubset.h"

void readData(const std::string inputFile, std::vector<int> &testData)
{
    std::ifstream in(inputFile);
    int value;
    while (in >> value)
        testData.push_back(value);
    in.close();
}

int main()
{
    std::vector<int> testData;

    for (size_t i = 0; i != 7; i++){
        std::string filename = "testData_";
        unsigned value = pow(10,i+1);
        filename += std::to_string(value);
        readData(filename, testData);
        clock_t start, end;
        std::cout << "******************************" << value << "*************************************" << std::endl;
        int max;
        if (i <= 2){
            start = clock();
            max = maxSubSum1(testData);
            end = clock();
            std::cout << "maxSubSum1输出最大子序列和为: " << max << "\n";
            std::cout << "maxSubSum1运行时间为: " << (double)(end - start) / CLOCKS_PER_SEC << std::endl; 

            start = clock();
            max = maxSubSum2(testData);
            end = clock();
            std::cout << "maxSubSum2输出最大子序列和为: " << max << "\n";
            std::cout << "maxSubSum2运行时间为:" << (double)(end - start) / CLOCKS_PER_SEC << std::endl; 
        }
        start = clock();
        max = maxSubSum3(testData);
        end = clock();
        std::cout << "maxSubSum3输出最大子序列和为: " << max << "\n";
        std::cout << "maxSubSum3运行时间为:" << (double)(end - start) / CLOCKS_PER_SEC << std::endl; 
        
        start = clock();
        max = maxSubSum4(testData);
        end = clock();
        std::cout << "maxSubSum4输出最大子序列和为: " << max << "\n";  
        std::cout << "maxSubSum4运行时间为:" << (double)(end - start) / CLOCKS_PER_SEC << std::endl; 
    }
    
    return 0;        
}



