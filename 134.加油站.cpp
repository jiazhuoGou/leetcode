/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 首先gas总和都不够肯定不行
        int sum = 0, total = 0, j = -1;
        for (auto item : gas)
        {
            sum += item;
        }
        for (auto item : cost)
        {
            total += item;
        }
        if (total > sum)
        {
            return -1;
        }

        sum = 0;
        total = 0;
        for (int i = 0; i < gas.size(); ++i)
        {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (sum < 0)
            {
                j = i;
                sum = 0;
            }
        }

        if (total >= 0)
            return j+1;
        else
            return -1;
    }
};
// @lc code=end

