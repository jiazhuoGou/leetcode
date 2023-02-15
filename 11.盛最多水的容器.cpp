/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    /**
     * @brief 双指针从两边向中间移动,小的才移动
     *      时间复杂度O(n), 空间复杂度O(1)
     * @param height 
     * @return int 
     */
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max = 0;
        for ( ; left < right; )
        {
            if(max < (right - left) * min(height[left], height[right]))
            {
                max = (right - left) * min(height[left], height[right]);
            }
            if(height[left] <= height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return max;
    }

    int min(int x, int y)
    {
        return x<y?x:y;
    }
};
// @lc code=end

