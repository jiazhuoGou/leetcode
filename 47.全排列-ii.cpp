/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector< vector<int> > res;
        vector<int> path;
        vector<int> used(nums.size(), 0);
        vector<int> seen(25, 0);
        dfs(nums, 0, seen, used, path, res);  
        return res;
    }

    void dfs(vector<int> &nums, int deep, vector<int> &seen, vector<int> &used, vector<int> path, vector< vector<int> > &res)
    {
        if (deep == nums.size())
        {   // 说明一个排列找完,每走一层深度加1
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        { 
            if (used[i] == 0 && seen[nums[i]+11] != 0 )
            {
                //seen[nums[i] + 11]--;
                continue;
            }
            

            if (used[i] == 0)
            {   // 这个数没有用过
                path.push_back(nums[i]);
                used[i] = 1;
                seen[nums[i] + 11]++;
                dfs(nums, deep+1,seen,  used, path, res);
                path.pop_back();    // 最后一个元素删除
                used[i] = 0;
                seen[nums[i] + 11]--;
            }
        }
    }
};
// @lc code=end

