/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2023-02-24 19:26:07
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2023-02-24 19:41:23
 * @FilePath: \leetcode\73.矩阵置零.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // O(m+n)空间
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<bool> rows(m, false), cols(n, false);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }
        cout << " records "<< endl;
        for (int i = 0; i < m; ++i)
        {
            if (rows[i] == true)
            {
                cout << "rows " << i << " " << endl;
                for (int j = 0; j < n; ++j)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (cols[i] == true)
            {
                cout << "cols " << i << " " << endl;
                for (int j = 0; j < m; ++j)
                {
                    matrix[j][i] = 0;
                }
            }
        }
    }
};
// @lc code=end

