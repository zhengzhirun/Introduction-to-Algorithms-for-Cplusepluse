/*************************************************************************
	> File Name: countingSort.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月09日 星期五 10时17分32秒
 ************************************************************************/

#ifndef _COUNTINGSORT_H
#define _COUNTINGSORT_H
#include <functional>
#include <vector>
// countingSort: 计数排序 算法导论8.2
/*
 * \parameter begin: 待排序序列的起始迭代器(也可以是指向数组中某元素的指针);
 * \parameter end: 待排序序列的终止迭代器(也可以是指向数组中某元素的指针);
 * \parameter maxVal: 待排序序列中的最大值.
 * \return void.
 *
 * 算法性能:时间复杂度 O(N). 空间复杂度O(N);算法只能够适应于整数排序.
 *
 * 算法基本思想: 对每一个输入元素x,确定小于x的元素的个数.利用这一信息,就可以直接
 *   --把x放在它在输出数组中的位置上了.例如,如果有17个元素小于x,则x就应该在第18个输出位置
 *   --上.当有几个元素相同时,这一方案要略做修改.因为不能把它们放在同一个输出位置上.
 * 
 * 算法特点: 计数排序已经不属于比较排序算法了, 在代码中也完全没有输入元素之间的比较操作.
 *   --计数排序一个重要的特点就是它是稳定的.具有相同值的元素在输出数组中的相对次序与它们 
 *   --在输入数组中的相对次序相同.也就是说,对两个相同的数来说,在输入数组中先出现数,在输出数组
 *   --中的相对次序也相同.
 *
 */
template<typename Iterator>
void countingSort(const Iterator begin, const Iterator end, 
                  const typename std::iterator_traits<Iterator>::value_type &maxVal)
{
    typedef typename std::iterator_traits<Iterator>::value_type T;      // 迭代器指向对象值的类型
    // 在编译的时候断言T的类型是不是整型,计数排序算法只支持整数类型的排序算法
    static_assert(std::is_integral<T>::value, "sequence to be must be integer!");
    auto size = std::distance(begin, end);
    if (size <= 1)
        return;
    std::vector<T> cuntingArray(maxVal+1,0);
    // 计数过程(cuntingArray[i]保存的就是等于i元素的个数)
    for (auto current = begin; current != end; ++current)
        cuntingArray[*current] += 1;
    // 通过加总计算确定每一个i=0,1,...,k,有多少输入元素是小于或等于i的
    for (decltype(cuntingArray.size()) i = 1; i != cuntingArray.size(); ++i)
        cuntingArray[i] += cuntingArray[i-1];
    // 把每个元素A[j]放到它输出数组B的正确位置上.
    std::vector<T> temSortArray(size,0);
    for (auto current = begin; current != end; ++current){
        temSortArray[cuntingArray[*current] - 1] = *current;
        cuntingArray[*current] -= 1;
    }
    std::copy(temSortArray.begin(), temSortArray.end(), begin);
}
#endif
