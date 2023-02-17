/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 对每一个数的两边进行遍历
        int longest = 0;
        unordered_map<int, bool> umap;
        for (int i = 0; i < nums.size(); i++)
        {
            umap[nums[i]] = false;
        }

        // 避免重复不需要每次在把map还原
        for (int i = 0; i < nums.size(); i++)
        {
            if (umap[nums[i]])
            {   // 已经用过
                continue;
            }
            umap[nums[i]] = true;
            int length = 1;
            // 遍历右边
            for (int k = nums[i] + 1; umap.find(k) != umap.end(); k++)
            {
                length++;
                umap[k] = true;
            }
            // 遍历左边
            for (int k = nums[i] - 1; umap.find(k) != umap.end(); k--)
            {
                length++;
                umap[k] = true;
            }

            if (length > longest)
            {
                longest = length;
            }
        }
        return longest;
    }
};
// @lc code=end

