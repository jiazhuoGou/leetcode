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
        /*
        // 从右往左找到第一个打破升序的数
        int i, j;
        for (i = nums.size() - 2; i >= 0 && nums[i] >= nums[i+1]; --i);
        if (i < 0)
        { // 说明该回到最初的模样
            sort(nums.begin(),nums.end());
            return;
        }

        // 这一步肯定是找的到的，不用判断j合不合法
        for (j = nums.size() - 1; nums[j] <= nums[i]; --j);
        swap(nums, i, j);
        reverse(nums, i + 1, nums.size() - 1);
        */
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
            reverse(rfirst, rlast); // 传的是引用，这里改了原数组也改了
            return false;
        }

        // 从右往左找第一个大于pivot的数
        //auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot)); // c++17已删除，改写下

        swap(*change, *pivot);
        reverse(rfirst, pivot);
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

