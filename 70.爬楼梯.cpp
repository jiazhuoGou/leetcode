/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2023-02-23 10:16:53
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2023-02-23 10:34:29
 * @FilePath: \leetcode\70.爬楼梯.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        // f(n) = f(n-1) + f(n-2),递归太慢

        int cur = 1, prev = 0, temp = 0;
        for (int i = 1; i <= n; ++i)
        {
            temp = cur;
            cur += prev;
            prev = temp;
            cout << "cur " << cur << "  ";
        }
        return cur;
        
    }

    
};
// @lc code=end

