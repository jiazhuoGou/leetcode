/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2023-02-15 15:18:48
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2023-02-15 15:22:21
 * @FilePath: \leetcode\26.删除有序数组中的重复项.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) 
            return 0;
        int index = 0;  // 没有重复的数
        for (int i = 1; i < nums.size(); i++) 
        {
            if (nums[index] != nums[i])
            {
                nums[++index] = nums[i];
            }
        }
        return index+1;
    }
};
// @lc code=end

