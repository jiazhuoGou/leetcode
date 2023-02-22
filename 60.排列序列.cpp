/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2023-02-21 09:54:59
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2023-02-22 14:59:50
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
        string s(n, '0');
        for (int i = 0; i < n; ++i)
        {
            s[i] += i + 1;
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
        return kth_permutation(s, k);
    }

    int factorial(int n)
    {
        int res = 1;
        for (int i = 1; i <= n; ++i)
        {
            res *= i;
        }
        return res;
    }

    // 一开始这个seq必须是第一个排列
    template<typename Sequence>
    Sequence kth_permutation(const Sequence &seq, int k)
    {
        const int n = seq.size();
        Sequence S(seq);
        Sequence res;

        int base = factorial(n - 1);    // 第一个数是/(n-1)!
        --k;    // 康托码是从0开始的
        // base 是/的阶乘
        for (int i = n - 1; i > 0; k %= base, base /= i, --i)
        {
            // 那么这一位就是倒数第quotient+1小的数, 一开始是从首位开始找的
            auto num = std::next(S.begin(), k / base);
            res.push_back(*num);
            S.erase(num);
        }
        res.push_back(S[0]);
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

