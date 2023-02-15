/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    // 动态规划
    int uniquePaths(int m, int n) {
        if(m == 1 && n == 1)
            return 1;
        
        vector<vector<int>> dp(m, vector<int>(n));
        
        // 填最后一行
        for (int j = 0; j < n; j++)
        {
            dp[m-1][j] = 1;
        }
        // 填最右边一列
        for (int i = 0; i < m - 1; i++)
        {
            dp[i][n-1] = 1;
        }
        // 从右下往左上填数
        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }


        return dp[0][0];
    }

    void print(vector<vector<int>> mat)
{
    for (vector<vector<int>>::iterator itr = mat.begin(); itr != mat.end(); itr++)
    {
        for (vector<int>::iterator it = (*itr).begin(); it != (*itr).end(); it++)
        {
            cout << *it << " ";
        }
        cout << "\n";
    }
}
};
// @lc code=end

