/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2022-10-22 19:27:01
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2022-10-24 19:54:14
 * @FilePath: \leetcode\1235.规划兼职工作.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=1235 lang=cpp
 *
 * [1235] 规划兼职工作
 */

// @lc code=start
class Solution {
public:
/**
 * @brief 
 * 
 * @param startTime 
 * @param endTime 
 * @param profit 
 * @return int 
 */
// 要先排序
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // 要先按照结束时间递增排序，再来动态规划，练习一下快排
        int cols = startTime.size();
        vector<vector<int>> mat(3, vector<int>(cols));
        // endtime是第一行，starttime是第二行，价值第三行
        for (int i = 0  ; i < cols; i++)
        {
            mat[0][i] = endTime[i];
        }
        for (int i = 0  ; i < cols; i++)
        {
            mat[1][i] = startTime[i];
        }
        for (int i = 0  ; i < cols; i++)
        {
            mat[2][i] = profit[i];
        }
        quick_sort(mat, 0, cols - 1);


        // dp][i]，前i个的最大值
        vector<int> dp(startTime.size());
        int time = 0, a = 0, b = 0;
        dp[0] = mat[3][0];
        for (int i = 1; i < dp.size(); i++) 
        {
            a = dp[i-1];    // 不选
            int front = find_begin(mat, mat[1][i]);
            if (front == -1)
            {
                dp[i] = dp[i-1];
            }
            else
            {
                b = dp[front] + profit[i];
                dp[i] = a>b?a:b;
            }
        }
        int max = 0;
        for (int i  = 0; i < dp.size(); i++)
        {
            if (dp[i] > max)
            {
                max = dp[i];
            }
        }
        return max;
    }

    /**
     * @brief 找到离x结尾的最大起始位置
     * 
     * @param endTime 
     * @param x 
     * @return int 
     */
    int find_begin(vector<vector<int>> mat, int x)
    {
        for (int i = mat[0].size() - 1; i >= 0; i--)
        {
            if (mat[0][i] <= x)
            {
                return i; 
            }
        }
        return -1;
    }

    // 以第一行作为标准
    void quick_sort(vector<vector<int>> mat, int low, int high)
    {
        if (low < high)
        {
            int base = partition(mat, low, high);
            quick_sort(mat, 0, base - 1);
            quick_sort(mat, base + 1, high);
        }
    }

    int partition(vector<vector<int>> &mat, int low, int high)
    {
        int x = mat[0][low];
        int key = low;
        while (low < high)
        {
            while (low < high && mat[0][high] >= x)
                high--;
            mat[0][low] = mat[0][high];
            while (low < high && mat[0][low] <= x)
                low++;
            mat[0][high] = mat[0][low];
        }
        mat[0][low] = x;
        return low;
    }
};
// @lc code=end

