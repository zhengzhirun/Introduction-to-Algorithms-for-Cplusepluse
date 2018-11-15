/*************************************************************************
	> File Name: exercise2.17b.cpp
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年10月30日 星期二 11时20分09秒
 ************************************************************************/
// 找出最小的正子序列和(如果序列全是负数则返回0)

#include <iostream>
using std::cout;    using std::endl;

#include <vector>
using std::vector;

#include <random>
using std::uniform_real_distribution;       using std::default_random_engine;

#include <algorithm>
using std::sort;

#include <time.h>
#include <float.h>

// 找出最小正子序列和的(O(n^2))算法
double minSubsetalgorithm1(const vector<double> &vec)
{
    double minSubsetSum = DBL_MAX;
    for (decltype(vec.size()) i = 0; i != vec.size(); ++i){
        double thisSum = 0.0;
        for (decltype(vec.size()) j = i; j != vec.size(); ++j){
            thisSum += vec[j];
            if (thisSum < minSubsetSum && thisSum >= 0.0)
                minSubsetSum = thisSum;
        }
    }
    if (minSubsetSum == DBL_MAX)
        minSubsetSum = 0.0;

    return minSubsetSum;
}

// 设计一个Item的数据结构
class Item{
private:
    double value;
    int index;

public:
    Item() = default;       // 默认构造函数
    Item(double, int);  // 自定义构造函数
    Item(const Item &);      // 拷贝构造函数
    Item& operator=(const Item &);       // 拷贝赋值运算符
    ~Item() = default;                    // 析构函数
    double getValue() const;
    double getValue();
    int getIndex() const;
    int getIndex();

friend bool operator<(const Item &, const Item &);
friend Item operator-(const Item &, const Item &);
};

// 自定义构造函数
Item::Item(double v, int i):
    value(v),
    index(i)
    {  }

// 拷贝构造函数
Item::Item(const Item &item):
    value(item.value),
    index(item.index)
    {  }

// 拷贝赋值运算符
Item& Item::operator=(const Item &item)
{
    value = item.value;
    index = item.index;

    return *this;
}

int Item::getIndex() const
{
    return index;
}

int Item::getIndex()
{
    return index;
}

double Item::getValue() const
{
    return value;
}

double Item::getValue()
{
    return value;
}


bool operator<(const Item &item1, const Item &item2)
{
    return (item1.value < item2.value);
}

Item operator-(const Item &item1, const Item &item2)
{
    Item item;
    item.value = item1.value - item2.value;
    item.index = item1.index - item2.index;

    return item;
}


// 找出最小正子序列和的O(nlog(n))算法
double minSubsetalgorithm2(const vector<Item> &vec)
{
    // 求出数组的前缀数组之和
    vector<Item> preAdd;
    double sum = 0.0;
    int sumIndex;
    for (decltype(vec.size()) i = 0; i != vec.size(); ++i){
        sum += vec[i].getValue();
        sumIndex = i;
        Item item(sum,sumIndex);
        preAdd.push_back(item);
    }

    // 按照value的大小从小到大排序
    sort(preAdd.begin(),preAdd.end());
    
    // 后一项减去前一项
    for (decltype(preAdd.size()) i = 0; i != preAdd.size() - 1; ++i)
        preAdd[i] = preAdd[i+1] - preAdd[i];
    // 删除preAdd中的最后一个元素
    preAdd.pop_back();

    // 找出小正值,并且index为正
    double minSubsetSum = DBL_MAX;
    for (decltype(preAdd.size()) i = 0; i != preAdd.size(); ++i){
        if (preAdd[i].getValue() < minSubsetSum && preAdd[i].getValue() >= 0 && preAdd[i].getIndex() > 0)
            minSubsetSum = preAdd[i].getValue();
    }

    if (minSubsetSum == DBL_MAX)
        minSubsetSum = 0.0;

    return minSubsetSum;
}

int main()
{
    vector<double> vec;
    // 生成-100~100之间的随机double型数据
    uniform_real_distribution<double> u(-100,100);
    default_random_engine e;
    // 随机生成一个数组
    for (int i = 0; i != 5000; ++i)
        vec.push_back(u(e));
    clock_t start, end;
    // 算法一:算法复杂度为(O(n^2))
    start = clock();
    double minSubsetSum = minSubsetalgorithm1(vec);
    end = clock();
    cout << "**************************minSubsetalgorithm1*******************" << endl;
    cout << "double序列的最小正子序列和为:" << minSubsetSum << ";所耗费的时间为" 
            << (double)(end - start) << endl;
    
    // 算法二:算法复杂度为(O(nlog(n)))
    vector<Item> itemVec;
    for (decltype(vec.size()) i = 0; i != vec.size(); ++i){
        Item item(vec[i],i);
        itemVec.push_back(item);
    }
    start = clock();
    minSubsetSum = minSubsetalgorithm2(itemVec);
    end = clock();
    cout << "**************************minSubsetalgorithm2*******************" << endl;
    cout << "double序列的最小正子序列和为:" << minSubsetSum << ";所耗费的时间为" 
            << (double)(end - start) << endl;

    return 0;
}
