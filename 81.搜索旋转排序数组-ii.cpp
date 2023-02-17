/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2023-02-17 15:17:15
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2023-02-17 15:40:28
 * @FilePath: \leetcode\81.搜索旋转排序数组-ii.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int mid = 0, left = 0, right = nums.size();
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            if (nums[mid] == nums[left])
            {
                left++;
                continue;
            }
            else if (nums[mid] > nums[left])
            {
                if (nums[left] <= target && nums[mid] > target)
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if (nums[mid] < target && nums[right - 1] >= target)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid;
                }
            }

        }
        return false;
    }
};
// @lc code=end

