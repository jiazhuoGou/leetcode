/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector< vector<int> > res;
        vector<int> path;
        vector<int> used(nums.size(), 0);
        dfs(nums, 0, used, path, res);  

        return res;
    }

    void dfs(vector<int> &nums, int deep, vector<int> &used, vector<int> path, vector< vector<int> > &res)
    {
        if (deep == nums.size())
        {   // 说明一个排列找完,每走一层深度加1
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i] == 0)
            {   // 这个数没有用过
                path.push_back(nums[i]);
                used[i] = 1;
                dfs(nums, deep+1, used, path, res);
                path.pop_back();    // 最后一个元素删除
                used[i] = 0;
            }
        }
    }
};
// @lc code=end

