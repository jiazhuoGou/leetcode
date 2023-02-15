/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // 仍然是用动态规划，填充数据
        int m = obstacleGrid.size(); // 行数
        int n = obstacleGrid[0].size();   // 列数
        vector<vector<long>> dp(m, vector<long>(n));
        if(obstacleGrid.size() == 1 && obstacleGrid[0].size() == 1 && obstacleGrid[0][0] == 1)
        {
            return 0;
        }
        if(obstacleGrid.size() == 1 && obstacleGrid[0].size() == 1 && obstacleGrid[0][0] == 0)
        {
            return 1;
        }
        
        // 在填数的时候要注意有障碍物的情况, -1代表走不通
        // 先填最后一行，要注意有障碍的情况
        int flag = 0; // 用来判断是否遇到障碍物 
        for(int j = n - 1; j >= 0; j--)
        {
            if(obstacleGrid[m-1][j] != 1 && flag != 1)
            {   // 说明这一格不是障碍物,它走得通
                dp[m-1][j] = 1;
            }
            else if (obstacleGrid[m-1][j] != 1 && flag == 1)
            {   // 说明他前面有障碍物，那么后续的都走不通
                dp[m-1][j] = -1;
            }
            else
            {   // 说明它是障碍物，走不通，并且后面的都走不通
                flag = 1;
                dp[m-1][j] = -1;
            }
        }
        // 填最右那列
        flag = 0;
        for(int i = m - 1; i >= 0; i--)
        {
            if(obstacleGrid[i][n-1] != 1 && flag != 1)
            {   // 说明这一格不是障碍物,它走得通
                dp[i][n-1] = 1;
            }
            else if (obstacleGrid[i][n-1] != 1 && flag == 1)
            {   // 说明他前面有障碍物，那么后续的都走不通
                dp[i][n-1] = -1;
            }
            else
            {   // 说明它是障碍物，走不通，并且后面的都走不通
                flag = 1;
                dp[i][n-1] = -1;
            }
        }
        // 填其他数，负数代表丢失的路径数
        flag = 0;
        for(int i = m - 2; i >= 0; i--)
        {
            for(int j = n - 2; j >= 0; j--)
            {
                if(obstacleGrid[i][j] == 1)
                {   // 说明它是障碍物
                    dp[i][j] = -1;
                }
                else
                {   // 不是障碍物直接加
                    if (dp[i+1][j] > 0 && dp[i][j+1] == -1)
                    {   // 下边大于0，走下边
                        dp[i][j] = dp[i+1][j];
                    }
                    else if (dp[i+1][j] == -1 && dp[i][j+1] > 0)
                    {   // 右边大于0，走右边
                        dp[i][j] = dp[i][j+1];
                    }
                    else if (dp[i][j+1] == -1 && dp[i+1][j] == -1)
                    {   //右边下边都走不通，他也走不通
                        dp[i][j] = -1;
                    }
                    else
                    {   // 右边下边都走的同，那么他也都走的通
                        dp[i][j] = dp[i+1][j] + dp[i][j+1];
                    }
                }
            }
        }
        return dp[0][0] < 0?0:dp[0][0];

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

