/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2023-02-23 10:37:19
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2023-02-24 19:23:39
 * @FilePath: \leetcode\1238.循环码排列.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
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
        // 格雷码
        vector<int> res;
        const int size = 1 << n;
        res.push_back(start);
        for (int i = 0; i < size && i != s; ++i)
        {

        }

        
        
        

        return res;
    }


    unsigned int binary_2_graycode(int n)
    {
        return n ^ (n >> 1);
    }
};
// @lc code=end

