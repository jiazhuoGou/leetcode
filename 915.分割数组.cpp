/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2022-10-24 18:15:48
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2022-10-24 18:53:23
 * @FilePath: \leetcode\915.分割数组.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=915 lang=cpp
 *
 * [915] 分割数组
 */

// @lc code=start
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        // index 和 i 不是同时更新
        // index 总是指向最小的那个
        int index = 0, left_max = nums[0], cur_max = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < left_max)
            {   // 有个更小的数
                index = i;
                left_max = cur_max;
            }
            else if (nums[i] > cur_max)
            {   //
                cur_max = nums[i];
            }
        }
        return index + 1;
    }
};
// @lc code=end

