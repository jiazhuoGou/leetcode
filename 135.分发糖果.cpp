/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2023-02-24 20:26:55
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2023-02-25 15:09:38
 * @FilePath: \leetcode\135.分发糖果.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        const int n = ratings.size();
        if (n == 1)
            return 1;

        vector<int> add(n);
        // 先每个人分一颗再来给相应的人增加
        for (int i = 1, inc = 1; i < n; ++i)
        {
            if (ratings[i] > ratings[i-1])
            {   // 右边 > 左边
                add[i] = max(inc++, add[i]);
            }
            else
            {
                inc = 1;
            }
        }

        // 从右往左检查一次
        for (int i = n - 2, inc = 1; i >= 0; --i)
        {
            if (ratings[i] > ratings[i+1])
            {
                add[i] = max(inc++, add[i]);
            }
            else
            {
                inc = 1;
            }
        }
        return accumulate(add.begin(), add.end(), 0) + n;
    }
};
// @lc code=end

