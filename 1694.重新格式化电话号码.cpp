/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2022-10-27 18:47:23
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2022-10-27 19:08:58
 * @FilePath: \leetcode\1694.重新格式化电话号码.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=1694 lang=cpp
 *
 * [1694] 重新格式化电话号码
 */

// @lc code=start
class Solution {
public:
    string reformatNumber(string number) {
        string str_number, res;
        for (auto entry : number)
        {
            if (entry >= '0' && entry <= '9')
            {
                str_number += entry;
            }
        }
        size_t index = 0;
        if (str_number.size() < 3)
        {
            res += str_number.substr(0, 2);
            return res;
        }
        while (index < str_number.size())
        {
            if (str_number.size() - index != 4)
            {
                res += str_number.substr(index, 3);
                res += '-';
                index += 3;
                cout << res << endl;
            }
            else
            {
                res += str_number.substr(index, 2);
                res += '-';
                index += 2;
                cout << res << endl;
            }
        }
        res.erase(res.end() - 1);
        return res;
    }
};
// @lc code=end

