/*************************************************************************
	> File Name: maxSubset.c
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年10月17日 星期三 10时34分57秒
 ************************************************************************/

#include "maxSubset.h"

// 最大相连子序列和立方级(O(n^3))算法
int maxSubSum1(const std::vector<int> &a)
{
    int maxSum = 0;

    for (decltype(a.size()) i = 0; i != a.size(); i++){
        for (auto j = i; j != a.size(); j++){
            int thisSum = 0;

            for (auto k = i; k != j; k++)
                thisSum += a[k];
            if (thisSum > maxSum)
                maxSum = thisSum;
        }
    }

    return maxSum;
}

// 最大相连子序列和平方级(O(n^2))算法
int maxSubSum2(const std::vector<int> &a)
{
    int maxSum = 0;

    for (decltype(a.size()) i = 0; i != a.size(); i++){
        int thisSum = 0;
        for (auto j = i; j != a.size(); j++){
            thisSum += a[j];
            if (thisSum > maxSum)
                maxSum = thisSum;
        }
    }

    return maxSum;
}

// 求取三个整数中的最大值
int max3(int a, int b, int c)
{
    int max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;

    return max;
}

// 最大相连子序列和递归算法(O(nlog(n)))
int maxSumRec(const std::vector<int> &a, 
        std::vector<int>::size_type left,
        std::vector<int>::size_type right)
{
    if (left == right)      // 基准情形 
        if (a[left] >= 0)
            return a[left];
        else
            return 0;

    auto center = (left + right) / 2;
    int maxLeftSum = maxSumRec(a, left, center);
    int maxRightSum = maxSumRec(a, center + 1, right);
    
    int maxLeftBorderSum = 0, leftBorderSum = 0;
    for (auto i = center; i != left; i--){
        leftBorderSum += a[i];
        if (leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }
    
    int maxRightBorderSum = 0, rightBorderSum = 0;
    for (auto j = center + 1; j != right; j++){
        rightBorderSum += a[j];
        if (rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }

    return max3(maxLeftSum, maxRightSum, 
            maxLeftBorderSum + maxRightBorderSum);
}

int maxSubSum3(const std::vector<int> &a)
{
    return maxSumRec(a, 0, a.size() - 1);
}

// 线性时间最大相连子序列和算法(O(n))
int maxSubSum4(const std::vector<int> & a)
{
    int maxSum = 0, thisSum = 0;

    for (decltype(a.size()) i = 0; i != a.size(); i++){
        thisSum += a[i];
        if (thisSum > maxSum)
            maxSum = thisSum;
        else if(thisSum < 0)
            thisSum = 0;
    }

    return maxSum;
}
