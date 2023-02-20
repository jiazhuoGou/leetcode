/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2023-02-20 09:06:00
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2023-02-20 09:21:24
 * @FilePath: \leetcode\2347.最好的扑克手牌.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=2347 lang=cpp
 *
 * [2347] 最好的扑克手牌
 */

// @lc code=start
class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        string res;
        unordered_map<int, int> umap;
        set<char> set;

        for (int i = 0; i < ranks.size(); i++)
        {
            umap[ranks[i]]++;
            if (umap[ranks[i]] == 2 && res.compare("Three of a Kind") != 0)
            {
                res = "Pair";
            }
            else if (umap[ranks[i]] >= 3)
            {
                res =  "Three of a Kind";
            }
            set.emplace(suits[i]);
        }
        if (set.size() == 1)
        {
            res = "Flush";
        }
        else if (set.size() > 1 && res == "")
        {
            res = "High Card";
        }


        return res;
    }
};
// @lc code=end

