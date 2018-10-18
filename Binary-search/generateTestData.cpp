/*************************************************************************
	> File Name: generateTestData.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年10月18日 星期四 13时25分43秒
 ************************************************************************/

#include <fstream>
#include <random>
#include <string>

void generateData(const std::string filename, size_t num)
{
    std::ofstream out(filename);
    std::uniform_int_distribution<int> u(-100,100);
    std::default_random_engine e;

    for (size_t i = 0; i != num; i++)
        out << u(e) << "\t" << u(e) << "\n";
    out.close();
}

int main(void)
{
    generateData("testData", 100);

    return 0;
}


