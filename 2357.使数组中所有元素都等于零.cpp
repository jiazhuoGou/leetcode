/*
 * @lc app=leetcode.cn id=2357 lang=cpp
 *
 * [2357] 使数组中所有元素都等于零
 */

// @lc code=start
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<bool> used(100, false);
        int count = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0 && !used[nums[i]])
            {
                count++;
                used[nums[i]] = true;
            }
        }
        return count;
    }
};
// @lc code=end

