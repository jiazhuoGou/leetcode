/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2023-02-23 10:37:19
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2023-02-23 11:14:40
 * @FilePath: \leetcode\1238.循环码排列.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=1238 lang=cpp
 *
 * [1238] 循环码排列
 */

// @lc code=start
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> res;
        const int size = pow(n);
        res.push_back(start);

        // 最后一位如果是0/1，那么可以+1/-1
        // 其余要变都是加上原数的乘或除2的几次方
        
        

        return res;
    }


    int pow(int n)
    {
        int k = 1;
        for (int i = 0; i < n; ++i)
        {
            k *= 2;
        }
        return k;
    }
};
// @lc code=end

