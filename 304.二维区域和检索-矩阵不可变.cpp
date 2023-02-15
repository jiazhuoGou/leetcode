/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
class NumMatrix {
private:
    vector<vector<int>> psum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = 0;
        if (r != 0) c = matrix[0].size();

        // 前缀和第一行跟第一列均为零，用来简化 sumRegion 边界判断
        psum.resize(r + 1, vector<int>(c + 1));
        for (int i = 0; i < r; i++) {
            int r_sum = 0;
            for (int j = 0; j < c; j++) {
                r_sum += matrix[i][j];
                psum[i + 1][j + 1] = r_sum + psum[i][j + 1]; 
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // 减去上方子矩阵和，减去左边子矩阵和，加上多减的重叠部分得到答案
        return psum[row2 + 1][col2 + 1] - psum[row1][col2 + 1]
            - psum[row2 + 1][col1] + psum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

