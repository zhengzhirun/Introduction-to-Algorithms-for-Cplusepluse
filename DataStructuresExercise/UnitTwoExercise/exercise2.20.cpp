/*************************************************************************
	> File Name: exercise2.20.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月01日 星期四 09时35分59秒
 ************************************************************************/

// 判断一个正整数是不是素数的算法

#include <iostream>
using std::cout;    using std::endl;

#include <cmath>
using std::sqrt;

#include <time.h>

// 素数除了本身和1没有其它的约数
// 算法1是一个O(N)级别的算法
bool isPrimer1(long long unsigned num)
{
    bool sign = true;
    for (long long unsigned i = 2; i != num; ++i){
        if (num % i == 0)       // 当num能被i整数
            sign = false;
    }

    return sign;
}

// 算法二提供一个O(N^(1/2))的算法
bool isPrimer2(long long unsigned num)
{
    bool sign = true;
    for (long long unsigned i = 2; i <= sqrt(num); ++i){
        if (num % i == 0)
            sign = false;
    }

    return sign;
}

// 将大于等于5的自然数表示为: 6x-1, 6x, 6x+1, 6x+2, 6x+3, 6x+4, 6x+5, 6(x+1), 6(x+1)+1
// 可以发现不在6的倍数两侧的数一定不是素数,再除去6的倍数自己
// 在6的倍数两侧的数不一定就是素数
bool isPrimer3(long long unsigned num)
{
    bool sign = true;
    
    if (num <= 25){
        for (long long unsigned j = 2; j <= sqrt(num); ++j)
            if (num % j == 0)   sign = false;
    }
    else{
        if (num % 6 != 1 && num % 6 != 5)
            sign = false;
        else{
            // 在6的倍数的两侧也不一定是素数
            for (long long unsigned i = 5; i <= sqrt(num); i += 6)
                if(num % i == 0 || num % (i + 2) == 0)
                    sign = false;
        }
    }
    return sign;
}



// 算法测试
int main()
{
    long long unsigned num = 10077698;
    clock_t start, end;
    // 算法1的测试
    start = clock();
    bool value = isPrimer1(num);
    end = clock();
    if (value)
        cout << num << "是一个素数." << endl;
    else
        cout << num << "不是一个素数." << endl;
    cout << "算法一所耗费的时间为:\t" << (double)(end-start) << endl;
    // 算法二的测试
    start = clock();
    value = isPrimer2(num);
    end = clock();
    if (value)
        cout << num << "是一个素数." << endl;
    else
        cout << num << "不是一个素数." << endl;
    cout << "算法二所耗费的时间为:\t" << (double)(end-start) << endl; 
    // 算法三的测试
    start = clock();
    value = isPrimer3(num);
    end = clock();
    if (value)
        cout << num << "是一个素数." << endl;
    else
        cout << num << "不是一个素数." << endl;
    cout << "算法三所耗费的时间为:\t" << (double)(end-start) << endl;
    
    return 0;    
}
