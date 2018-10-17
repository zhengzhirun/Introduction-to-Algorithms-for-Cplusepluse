/*************************************************************************
	> File Name: generateTestData.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年10月17日 星期三 19时19分01秒
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include <string>

void writeData(const std::string filename, size_t iterations)
{
    std::uniform_int_distribution<int> u(-100,100);
    std::default_random_engine e;

    std::ofstream out(filename);
    for (size_t i = 0; i != iterations; i++)
        out << u(e) << "\t" << u(e) << "\t" << u(e) << "\t" << u(e) << "\t" << u(e) << "\n";
    out.close();
}

int main()
{
    
    for (size_t i = 0; i != 7; i++){
        std::string filename = "testData_";
        unsigned value = pow(10,i+1);
        filename += std::to_string(value);
        size_t iterations = 2 * pow(10,i);
        writeData(filename, iterations);
    }
   
    return 0;
}


