/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2023-02-15 15:06:58
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2023-02-15 15:37:04
 * @FilePath: \leetcode\80.删除有序数组中的重复项-ii.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0, index = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == nums[index])
            {
                count++;
            }
            else
            {
                nums[index] = nums[i];
            }
            
            if (count == 2)
            {
                index = i;
                count = 0;
            }
            
        }

        return index+1;
    }
};
// @lc code=end

