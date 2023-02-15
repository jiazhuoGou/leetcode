/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2022-10-18 15:38:23
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2022-10-18 18:57:56
 * @FilePath: \leetcode\902.最大为-n-的数字组合.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=902 lang=cpp
 *
 * [902] 最大为 N 的数字组合
 */

// @lc code=start
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        /* 遍历1到n，查每一个数的每位是不是在里面,时间爆炸
            int cnt = 0, temp = 0;
            string str, S;
            for (auto digit : digits)
            {
                S = S + digit;
            }
            cout << S << endl;
            for (int i = 1; i < n; i++) 
            {
                temp = 0;
                str = int_2_string(i);
                for (auto s : str)
                {
                    if (S.find(s) != -1)
                    {
                        temp++;
                    }
                }
                if (temp == str.size())
                {
                    cnt++;
                }
            }
            return cnt;
            */

           

    }

    string int_2_string(int n)
    {
        string str;
        int k;
        while (n != 0)
        {
            k = n % 10;
            str = (char)(k + '0') + str;
            n /= 10;
        }
        return str;
    }
};
// @lc code=end

