/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /**
         * @brief 滑动窗口硬算，两个指针, 时间复杂度O(n^2)
         * 再开一集合，判断插入的是否有重复
         */
        set<char> Set;
        int Max = 0;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            cnt = 0;
            Set.insert(s[i]);
            cnt++;  // 因为一来就插了一个
            for (int j = i + 1; j < s.size() ; j++)
            {
                auto ret = Set.insert(s[j]);
                if(ret.second == false)   
                    break;
                else
                    cnt++;
            }
            if(Max < cnt) Max = cnt;
            Set.clear();
        }
        return Max;
    }
};
// @lc code=end

