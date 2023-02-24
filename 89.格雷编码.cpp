/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        const int size = 1 << n;
        for (int i = 0; i < size; ++i)
        {
            res.push_back(binary_2_graycode(i));
        }
        
        return res;
    }

    unsigned int binary_2_graycode(int n)
    {
        return n ^ (n >> 1);
    }
};
// @lc code=end

