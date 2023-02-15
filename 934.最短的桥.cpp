/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2022-10-25 19:12:53
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2022-10-27 18:47:13
 * @FilePath: \leetcode\934.最短的桥.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */

// @lc code=start
class Solution {
public:

    queue<pair<int, int>> q;

    // dfs + bfs
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        boolean falg = false;
        for (int i = 0; !flag && i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(grid, i, j, n);
                    break;
                }
                    
            }
        }
        

        return 0;
    }

    void dfs(vector<vector<int>> &grid, int i, int j, int n, boolean &flag)
    {
        if (i < 0 || j < 0 || i >= n || j >= n)
        {   // i, j不在范围内不行
            return;
        }
        if (grid[i][j] != 1)
        {
            grid[i][j] = 2;
            return;
        }
        pair<int, int> temp(i, j);
        flag = true;
        q.push(temp);
        grid[i][j] = 2;
        dfs(grid, i+1, j, n);  // 下边
        dfs(grid, i-1, j, n);  //  上边
        dfs(grid, i, j-1, n);  // 左边
        dfs(grid, i, j+1, n);  // 右边
    }

    int bfs(vector<vector<int>> grid)
    {

        return 0;
    }
};
// @lc code=end

