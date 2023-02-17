/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2023-02-17 14:35:18
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2023-02-17 15:09:02
 * @FilePath: \leetcode\33.搜索旋转排序数组.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    // 就是普通二分查找, 注意mid判断时的边界
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size(), mid = 0;
        // left 始终指向一个实数，right指的实数的后一位
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target )
            {
                return mid;
            }
            if (nums[left] <= nums[mid])
            {
                if (nums[mid] >= target && nums[left] <= target)
                {   
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {   // 始终要找递增的序列那边
                if (nums[mid] <= target && target <= nums[right-1])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid;
                }
            }
        }
        return -1;

    }
};
// @lc code=end

