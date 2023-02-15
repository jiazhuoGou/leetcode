/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 键是出现的和，值是该和出现的次数
        // 也是参考了官方的答案
        unordered_map<int , int> map;
        int sum = 0, cnt = 0;
        map[0] = 1;
        for (int i = 0; i < nums.size(); i++) 
        {
            sum += nums[i]; // sum是第i项的前缀和
            cnt += map[sum - k]; // 这一步的前缀和是否出现过
            map[sum]++; // 这一步的前缀和存起来
        }
    return cnt;
    }
};
// @lc code=end

