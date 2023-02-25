/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // O(1)是常数空间,，一个数出现了三次，那么其二进制对应位也会出现三次1
        // 只有一次1的说明就是那个single number
        const int n = sizeof(int) * 8;
        int count[n];
        fill(count, count + n, 0);

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = n - 1, k = 0; j >=0 ; --j, ++k)
            {
                count[j] += (nums[i] >> k) & 1;
                count[j] %= 3;
            }
        }

        
        int result = 0;
        for (int i  = n - 1, k = 0; i >= 0; --i, ++k)
        {
                result += (count[i] << k);
        }
        return result;

    }
};
// @lc code=end

