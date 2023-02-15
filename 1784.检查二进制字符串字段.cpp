/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2022-10-27 19:20:02
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2022-10-27 19:28:28
 * @FilePath: \leetcode\1784.检查二进制字符串字段.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE   
 */
/*
 * @lc app=leetcode.cn id=1784 lang=cpp
 *
 * [1784] 检查二进制字符串字段
 */

// @lc code=start
class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = 0;
        s += '0';
        for (int i = 0; i <= s.size(); i++)
        {
            if (s[i] - '0' == 1 && s[i+1] - '0' == 1)
            {
                continue;
            }
            if (s[i] - '0' == 1 && s[i+1] - '0' == 0)
            {
                cnt++;
                i++;
            }
        }
        if (cnt > 1)
        {
            return false;
        }
        return true;
    }
};
// @lc code=end

