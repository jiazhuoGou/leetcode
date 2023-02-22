/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2023-02-22 20:01:20
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2023-02-22 20:29:39
 * @FilePath: \leetcode\42.接雨水.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        // 找出最大的柱子
        int water = 0;
        int max = 0;
        const int n = height.size();
        for (int i = 1; i < n; ++i) 
        {
            if (height[i] > height[max])
            {
                max = i;
            }    
        }

        // 处理左边
        for (int i = 0, peak = 0; i < max; ++i)
        {
            if (height[i] > peak)
            {
                peak = height[i];
            }
            else
            {
                water += peak - height[i];
            }
        }

        // 处理右边
        for (int i = n - 1, peak = 0; i > max; --i)
        {
            if (height[i] > peak)
            {
                peak = height[i];
            }
            else
            {
                water += peak - height[i];
            }

        }
        return water;
    }
};
// @lc code=end

