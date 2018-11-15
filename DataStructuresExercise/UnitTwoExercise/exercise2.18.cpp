/*************************************************************************
	> File Name: exercise2.18.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年10月31日 星期三 19时36分48秒
 ************************************************************************/

#include <iostream>
using std::cout;    using std::endl;

double f(double x)
{
    return x * x * x;
}

double dichotomy(double low, double high)
{

    if (f(low) <= 0 && f(high) >= 0){
        double center = (low + high) / 2.0;
        while(( (f(center) - 0) > 0 ? (f(center) - 0) : (0 - f(center)) ) > 1e-10){
            if (f(center) > 0)
                high = center;
            if (f(center) < 0)
                low = center;
            center = (low + high) / 2.0;
        }
        return center;
    }else{
        cout << "输入有误" << endl;
        return -1;
    }
}

int main()
{
    double low = -10, high = 100;
    double value = dichotomy(low, high);
    cout << value << endl;

    return 0;
}


