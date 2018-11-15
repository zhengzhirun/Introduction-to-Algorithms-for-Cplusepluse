/*************************************************************************
	> File Name: bucketSort.h
	> Author: ZhirunZheng 
	> Mail: jiangxizhengzhirun@163.com 
	> Created Time: 2018年11月10日 星期六 20时46分42秒
 ************************************************************************/

#ifndef _BUCKETSORT_H
#define _BUCKETSORT_H
#include <cassert>
#include <vector>
#include <algorithm>
#include "../quick_sort/quickSort.h"
const std::size_t real_bucket_num = 10;     // 桶排序时划分10个小区间
// bucketSort: 桶排序 算法导论8.4
/*
 * \parameter begin: 待排序序列的起始迭代器(也可以是指向数组中某元素的指针);
 * \parameter end: 待排序序列的终止迭代器(也可以是指向数组中某元素的指针);
 * \parameter min_value: 待排序序列元素的下界(不一定是最紧下界);
 * \parameter max_value: 待排序序列元素的上届(不一定是最紧上界);
 * \return void.
 *
 * 算法基本思想: 桶排序将[0, 1]区间划分为n个相同大小的子区间, 或称为桶.
 *               然后,将n个输入数分别放到各个桶中.为了得到输出结果,我们先对
 *               每个桶中的数进行排序, 然后遍历每个桶, 按照次序把各个桶中的
 *               元素列出来即可.
 * 算法性能: 桶排序算法假设输入数据服从均匀分布,平均情况下它的时间代价是O(N).
 *      --非原地排序算法.
 */
template<typename Iterator>
void bucketSort(const Iterator begin, const Iterator end, 
                const typename std::iterator_traits<Iterator>::value_type &min_value,
                const typename std::iterator_traits<Iterator>::value_type &max_value)
{
    assert(min_value < max_value);  // 确保最小值要小于最大值
    // 迭代器指向对象值的类型
    typedef typename std::iterator_traits<Iterator>::value_type T;
    std::vector<T> buckets[real_bucket_num];
    for (auto current = begin; current != end; ++current){
        // 归一化处理
        int index = (*current - min_value) * real_bucket_num / (max_value - min_value);
        buckets[index].push_back(*current);     // 把元素放到桶中
    }
    // 对每一个区间进行排序
    std::size_t inserted_total = 0;
    for (int i = 0; i != real_bucket_num; ++i){
        quickSort(buckets[i].begin(), buckets[i].end());
        std::copy(buckets[i].begin(), buckets[i].end(), begin + inserted_total);   // 非原址排序
        inserted_total += buckets[i].size();
    }
}
#endif
