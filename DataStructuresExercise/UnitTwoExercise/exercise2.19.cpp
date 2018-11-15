/*************************************************************************
	> File Name: exercise2.19.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年10月31日 星期三 19时56分30秒
 ************************************************************************/

#include <iostream>
using std::cout;    using std::endl;
using std::ostream;

#include <vector>
using std::vector;

#include <random>
using std::uniform_real_distribution;   using std::default_random_engine;

#include <float.h>

//////////////////////////////定义一个新的数据结构//////////////////////////////////////////
class Information{
friend ostream& operator<<(ostream &, const Information &);
friend bool operator<(const Information &, const Information &);
friend Information operator+(const Information &, const Information &);
private:
    double maxSum;
    int index[2];
public:
    Information();   // 默认构造函数
    Information(double, int, int);     // 构造函数
    ~Information() = default;       // 默认的析构函数
    Information& operator=(const Information&);     // 拷贝赋值运算符
    Information(const Information&);        // 拷贝构造函数
    double getValue(const Information &) const;
    
};

Information operator+(const Information &inf1, const Information &inf2)
{
    Information inf;
    inf.maxSum = inf1.maxSum + inf2.maxSum;
    inf.index[0] = inf1.index[0] > inf2.index[0] ? inf2.index[0] : inf1.index[0]; 
    inf.index[1] = inf1.index[1] > inf2.index[1] ? inf1.index[1] : inf2.index[1]; 

    return inf;
}

Information::Information()
{
    maxSum = 0.0;
    index[0] = 0;
    index[1] = 0;
}

Information::Information(double value, int i, int j)
{
    maxSum = value;
    index[0] = i;
    index[1] = j;
}

Information& Information::operator=(const Information &inf)
{
    maxSum = inf.maxSum;
    index[0] = inf.index[0];
    index[1] = inf.index[1];

    return *this;
}

Information::Information(const Information &inf)
{
    maxSum = inf.maxSum;
    index[0] = inf.index[0];
    index[1] = inf.index[1];
}

ostream& operator<<(ostream &os, const Information &inf)
{
    os << "数组的最大子序列为:\t" << inf.maxSum << "\n"
        << "最大子序列的下标位置为:\t" << inf.index[0] << "\t"
        << inf.index[1];

    return os;
}

bool operator<(const Information &inf1, const Information &inf2)
{
    return inf1.maxSum < inf2.maxSum;
}

double Information::getValue(const Information &inf) const
{
    return inf.maxSum;
}

/////////////////////////////////////算法设计///////////////////////////////////////////
// 算法1:暴力搜索,算法复杂度为(O(N))
Information maxSubsetSum1(const vector<double> &vec)
{
    Information maxSubsetSum(DBL_MIN,0,0);
    for (decltype(vec.size()) i = 0; i != vec.size(); ++i){
        double thisSum = 0.0;
        for (decltype(vec.size()) j = i; j != vec.size(); ++j){
            thisSum += vec[j];
            Information thisSumInf(thisSum, i, j);
            if (maxSubsetSum < thisSumInf)
                maxSubsetSum = thisSumInf;
        }
    }

    return maxSubsetSum;
}

Information max3(const Information &inf1, const Information &inf2, const Information &inf3)
{
    Information max = inf1;
    if (max < inf2)
        max = inf2;
    if (max < inf3)
        max = inf3;

    return max;
}

// 算法二:分治递归策略
Information maxSubsetSum2(const vector<double> &vec, int left, int right)
{
    // 基准情形
    if (left == right){
        Information inf(vec[left], left, right);
        return inf;
    }
    
    // 递归情形
    int center = (left + right) / 2;
    Information maxLeftSum = maxSubsetSum2(vec, left, center);
    Information maxRightSum = maxSubsetSum2(vec, center + 1, right);

    // 左边的情况
    Information maxLeftBounderSum(DBL_MIN, 0, 0);
    double leftBounderSum = 0.0;
    for (int i = center; i >= left; --i){
        leftBounderSum += vec[i];
        Information leftBounderSumInf(leftBounderSum, i, center);
        if (maxLeftBounderSum < leftBounderSumInf)
            maxLeftBounderSum = leftBounderSumInf;
    }

    // 右边的情形
    Information maxRightBounderSum(DBL_MIN, 0, 0);
    double rightBounderSum = 0.0;
    for (int i = center + 1; i <= right; ++i){
        rightBounderSum += vec[i];
        Information rightBounderSumInf(rightBounderSum, center + 1, i);
        if (maxRightBounderSum < rightBounderSumInf)
            maxRightBounderSum = rightBounderSumInf;
    }

    // 返回最大值
    return max3(maxLeftSum, maxRightSum, maxLeftBounderSum + maxRightBounderSum);
}

// 算法三: 联机算法,算法复杂度为(O(N))
Information maxSubsetSum3(const vector<double> &vec)
{
    Information maxSubsetSum(DBL_MIN, 0, 0);
    double thisSum = 0.0;
    int j = 0, index = 0;
    for (decltype(vec.size()) i = 0; i != vec.size(); ++i){
        index += 1;
        thisSum += vec[i];
        Information inf(thisSum, j, i);
        if (maxSubsetSum < inf)
            maxSubsetSum = inf;
        
        else if (thisSum < 0){
            thisSum = 0.0;
            j = j + index;
            index = 0;
        }
    }

    return maxSubsetSum;
}

//////////////////////////算法测试//////////////////////////////
int main()
{
    vector<double> vec;
    // 生成-100到100之间的随机double型数据
    uniform_real_distribution<double> u(-10,10);
    default_random_engine e;
    // 随机生成一个数组
    for (int i = 0; i != 20000; ++i)
        vec.push_back(u(e));
    // 算法一的测试
    Information inf = maxSubsetSum1(vec);
    cout << inf << endl;

    // 算法二的测试
    inf = maxSubsetSum2(vec, 0, vec.size() - 1);
    cout << inf << endl;

    // 算法三的测试
    inf = maxSubsetSum3(vec);
    cout << inf << endl;

    return 0;
}
