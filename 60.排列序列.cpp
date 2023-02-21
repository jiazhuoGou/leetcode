/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2023-02-21 09:54:59
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2023-02-21 10:32:13
 * @FilePath: \leetcode\60.排列序列.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%
 */
/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        string res(n, '0');
        for (int i = 0; i < n; i++)
        {
            res[i] += i + 1;
        }

        /*
        普通想法
        for (int i = 1; i < k; i++)
        {
            next_permutation(res.begin(), res.end());
        }*/

        /*
            康托码
        */
        


        return res;
    }


    template <typename vecIt>
    bool next_permutation(vecIt first, vecIt last)
    {
        // 使用逆迭代器简化操作
        const auto rfirst = reverse_iterator<vecIt>(last);
        const auto rlast = reverse_iterator<vecIt>(first); // rlast是第一个元素更前的一个，不是有效的

        // 找第一个从右往左打破升序的数
        auto pivot = next(rfirst);
        for ( ; pivot != rlast && *pivot >= *prev(pivot); ++pivot);
        // 如果没找到这样的数，说明这个序列是最大的了，回到最初
        if (pivot == rlast)
        {
            // 指针是左闭右开,rlast是指向有效位的后一个
            std::reverse(rfirst, rlast); // 传的是引用，这里改了原数组也改了
            return false;
        }
        

        // 从右往左找第一个大于pivot的数
        //auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot)); // c++17已删除，改写下
        auto temp_itr = rfirst;
        for ( ; *temp_itr <= *pivot; ++temp_itr);
        auto change = temp_itr;
        

        std::swap(*change, *pivot);
        std::reverse(rfirst, pivot);
        return true;
    }
};
// @lc code=end

