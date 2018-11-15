/*************************************************************************
	> File Name: radixSort.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月10日 星期六 15时25分34秒
 ************************************************************************/

#ifndef _RADIXSORT_H
#define _RADIXSORT_H

#include <functional>
#include <cmath>
#include <cassert>
#include <vector>
// digi_on_N: 获取正整数指定位数上的数字.
/*
 * \parameter num: 待抽取数字的正整数;
 * \parameter n: 指定的位数(0表示个位, 1表示十位, ...依次类推);
 * \return 指定正整数指定位数上的数字.
 *
 * 注意:这里的T必须为某个整数类型, 由static_assert(std::is_integral<T>::value, "...")确保;
 *
 */
template<typename T> 
T digi_on_N(T num, std::size_t n)
{
    // 必须针对整数类型才能取指定位数上的数字
    static_assert(std::is_integral<T>::value, "T must be integer!");
    return num / static_cast<T>(std::pow(10,n)) % 10;
}
// countingSort: 计数排序  算法导论8.2
/*
 * \parameter begin: 待排序序列的起始迭代器(也可以是指向数组中某元素的指针);
 * \parameter end: 待排序序列的终止迭代器(也可以是指向数组中某元素的指针);
 * \parameter maxVal: 待排序序列中的最大值;
 * \parameter n: 指定按照位数排序(0表示个位, 1表示十位, ...依次类推);
 * \return void.
 *
 * 算法性能: 算法的时间复杂度为O(N);
 * 算法特点: 保证了稳定性, 稳定性在计数排序算法中是非常重要的.稳定性就是在序列中相同的数字,经过
 *           排序算法以后依旧按照原先出现的次序出现.
 * 算法基本思想: 对每一个输入元素x, 确定小于x的元素个数. 利用这一信息,就可以直接把x放到它在输出数组
 *           中的位置上了.
 * 此算法并不属于原址排序算法, 同时也不属于比较排序算法.
 */
template<typename Iterator>
void countingSort(const Iterator begin, const Iterator end,
                  const typename std::iterator_traits<Iterator>::value_type &maxVal, std::size_t n)
{
    // 迭代器指向元素的类型
    typedef typename std::iterator_traits<Iterator>::value_type T;
    auto size = std::distance(begin, end);
    std::vector<T> countingArray(maxVal + 1, 0);
    // 等于i元素的个数
    for (auto current = begin; current != end; ++current)
        countingArray[digi_on_N(*current, n)] += 1;
    // 记住比该数小的元素共有多少个
    for (decltype(countingArray.size()) i = 1; i != countingArray.size(); ++i)
        countingArray[i] += countingArray[i - 1];
    // 把元素放回到正确的位置上
    std::vector<T> tempResult(size, 0);
    for (auto current = end - 1; current !=  begin - 1; --current){
        tempResult[countingArray[digi_on_N(*current, n)] - 1] = *current;
        countingArray[digi_on_N(*current, n)] -= 1;
    }    
    // 把排序好的元素返回到数组中
    std::copy(tempResult.begin(), tempResult.end(), begin);
}
// radixSort: 基数排序 算法导论8.3.
/*
 * \parameter begin: 待排序序列的起始迭代器(也可以是指向数组中某元素的指针);
 * \parameter end: 待排序序列的终止迭代器(也可以是指向数组中某元素的指针);
 * \parameter radix_width: 待排序元素(必须是整数)的最大位宽, 必须非0(由assert(radix_width!=0)确保);
 * \return void.
 *
 * 算法性能:给定n个d位数,其中每一个数为有k个可能的值.如果基数排序算法使用的是稳定的计数排序算法那么
 *          算法的时间复杂度为O(d(n+k)).
 * 算法的基本思想: 依次对所给数字中的个位, 十位,...排序(注意,一定要使用稳定的排序算法).
 * 此算法不属于比较排序算法, 是否是原址排序取决于你对每一位数所使用的排序算法.
 *
 */
template<typename Iterator>
void radixSort(const Iterator begin, const Iterator end, std::size_t radix_width)
{
    // 迭代器指向元素的类型
    typedef typename std::iterator_traits<Iterator>::value_type T; 
    assert(radix_width != 0);   // 检测位数为有效位, 0属于无效位
    // 在编译的时候确保 (基数排序只适合对整数类型的数据进行排序)
    static_assert(std::is_integral<T>::value, "sequence to be sorted must be integer!");
    auto size = std::distance(begin, end);
    if (size <= 1)
        return;
    // 对每一位都使用计数排序方法进行排序
    for (int i = 0; i <= radix_width; ++i)
        countingSort(begin, end, 9, i);
}
#endif
