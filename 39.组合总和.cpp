/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector< vector<int> > res;
        int len = candidates.size();
        // 画图分析后是一棵树的结构，所以记录下序列
        vector<int> path;
        // 先排序，方便减枝，不断减下去的时候结果如果为负，说明以后的都不可能了
        sort(candidates.begin(), candidates.end());
        dfs(len, candidates, target, 0, path, res);
        return res;
    }
    /**
     * @brief 深度优先遍历，找出符合的序列
     * 
     * @param len 数组长度
     * @param candidates 数组
     * @param target 目标值
     * @param begin 开始起点
     * @param path 序列
     * @param res 返回的结果
     */
    void dfs(int len, vector<int> candidates, int target, int begin, vector<int> path, vector<vector<int>>& res)
    {
        cout << "当前的索引 : " << begin << "  ";
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
        for (int i = begin; i < len; i++)
        {
            if (target - candidates[i]< 0)
            {   // 因为之后不可可能再增加了
                break;
            }   // 这里之前还加了if判断是否大于0，是错的，因为等于0不会做事，所以应该是大于等于0              
            if (target - candidates[i] >= 0)
            {
                // 还能往下走就走
                path.push_back(candidates[i]);
                dfs(len, candidates, target - candidates[i], i, path, res);
                path.pop_back();    // 递归每退出一层，都要将path删除一个，因为要把之前寸的删掉，开始找一个新的序列
            }
        }
        
    }

};
// @lc code=end

