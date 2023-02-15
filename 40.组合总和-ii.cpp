/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        for(vector<int>::iterator it = candidates.begin(); it != candidates.end(); it++)
        {
            cout << " " << *it;
        }
        cout << "\n";

        dfs(candidates, 0, target, path, res);
        return res;
    }
    /**
     * @brief 与第一种题类似
     * 
     * @param candidates 数组
     * @param target 目标值
     * @param res 保存的结果
     * @param path 找到的序列
     */
    void dfs(vector<int>& candidates, int begin, int target, vector<int> path, vector< vector<int> > &res)
    {   
        for (int j = 0; j < path.size(); j++)
            {
                cout << " " << path[j];
            }
            cout << "\n";
        if (target == 0)
        {   //  找到一个序列
            res.emplace_back(path);
            return;
        }
        
        for (int i = begin; i < candidates.size(); i++)
        {
            if (i > begin && candidates[i] == candidates[i-1])
            {
                continue;
            }
            if (target - candidates[i] < 0)
            {
                break;  // 减枝
            }
            // 减去后不小于0， 说明该数可以添加进序列
            path.push_back(candidates[i]);
            dfs(candidates, i+1, target-candidates[i], path, res);
            path.pop_back();    //  删除最后一个元素
            cout << "删除末尾元素之后 : ";
            for (int j = 0; j < path.size(); j++)
            {
                cout << " " << path[j];
            }
            cout << "\n";
        }
        
    }
};
// @lc code=end

