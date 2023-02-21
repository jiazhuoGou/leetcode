/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2023-02-15 15:07:35
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2023-02-21 10:10:11
 * @FilePath: \leetcode\31.下一个排列.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
/**
 * @brief 应该是算当前排列的逆序数，逆序数是从0开始,1234的逆序数就是0
 * 然后判断逆序数如果 = nums.size() - 1，
 *                  那么就找出比第一个数大1的数作首元素，其他元素从小到大排序
 *              如果 = nums.size() 
 *                  那么直接从小到大排序，回到起始排列
 *              如果是其他情况
 *              上述分析无效，看的官方解释，找一个较小的大数跟一个差最小的小数交换
 *                  
 * @param nums 排列 
 */
    void nextPermutation(vector<int>& nums) {

        // 高端写法
        next_permutation(nums.begin(), nums.end());
        

        
    }

    // 通用模板函数
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

    void swap(vector<int> &nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp; 
    }

    // 逆转下标i到j的数
    void reverse(vector<int> &nums, int i, int j)
    {
        for ( ; i <= j; )
        {
            swap(nums, i, j);
            i++;
            j--;
        }
    }
    
};
// @lc code=end

