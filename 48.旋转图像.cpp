/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 沿副对角线翻转一次，沿中间上下翻转一次
        const int n = matrix.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n - i - 1; ++j)
            {
                swap(matrix[i][j], matrix[n- j - 1][n - i - 1]);
            }
        }

        for (int i = 0; i < n / 2; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                swap(matrix[i][j], matrix[n-i-1][j]);
            }
        }

    }
};
// @lc code=end

