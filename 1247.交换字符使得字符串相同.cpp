/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2023-02-25 14:15:43
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2023-02-25 14:39:38
 * @FilePath: \leetcode\1247.交换字符使得字符串相同.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=1247 lang=cpp
 *
 * [1247] 交换字符使得字符串相同
 */

// @lc code=start
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        // 判断 xy, yx是否出现偶数次
        int xy = 0, yx = 0;
        for (int i = 0; i < s1.length(); ++i)
        {
            if (s1[i] ==  'x' && s2[i] == 'y')
                xy++;
            else if (s1[i] == 'y' && s2[i] == 'x')
                yx++;

        }

        return (xy+yx) & 0x01 == 1?-1:(xy/2 + yx/2 + xy%2 + yx%2);
    

    }
};
// @lc code=end

