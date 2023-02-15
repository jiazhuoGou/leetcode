/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2022-10-20 18:51:34
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2022-10-20 19:41:36
 * @FilePath: \leetcode\779.第k个语法符号.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=779 lang=cpp
 *
 * [779] 第K个语法符号
 */

// @lc code=start
class Solution {
public:
    int kthGrammar(int n, int k) {
        /* 暴力 mingxianchaoshi 
        vector<vector<int>> arr;
        vector<int> temp;
        temp.push_back(0);
        arr.push_back(temp);
        temp.clear();
        for (int i = 1; i < n; i++) 
        {
            temp.clear();
            for (vector<int>::iterator it = arr[i-1].begin(); it != arr[i-1].end(); it++)
            {
                if (*it == 0)
                {
                    temp.push_back(0);
                    temp.push_back(1);
                }
                else 
                {
                    temp.push_back(1);
                    temp.push_back(0);
                }
            }
            arr.push_back(temp);
        }

        return arr[n-1][k-1];
        */

        // recursion
        

        if (n == 1 && k == 1)
        {
            return 0;
        }
        int a = kthGrammar(n-1, (k+1) / 2);
        int b = -(a-1);
        if (k & 0x01 != 0)
        { // odd number
            return a;
        }
        else
        {
            return b;
        }


    }
};
// @lc code=end

