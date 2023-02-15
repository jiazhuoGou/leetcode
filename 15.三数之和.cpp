/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
/**
 * @brief 三重循环，第三重从右往左算，先排序
 * 
 * @param nums 
 * @return vector<vector<int>> 
 */
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > vec;//初始化一个m行n列的元素值全为0的二维数组
        if (nums.size() < 3)
        {
            return vec;
        }
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            if(i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }
                int k = nums.size() - 1;
                for (int j = i + 1; j < nums.size(); j++)
                {
                    if ((j > i + 1) && (nums[j] == nums[j-1]))
                    {
                        continue;
                    }
                        while( (j < k) && (nums[i] + nums[j] + nums[k] > 0) )
                        {
                            --k;
                        }
                        if(j == k)
                        {
                            break;
                        }
                        if (check(nums[i], nums[j], nums[k]))
                        {   // 说明找到
                            vec.push_back({nums[i], nums[j], nums[k]});
                        }
                }
        }
        
        return vec;

    }

    bool check(int a, int b, int c)
    {
        return ((a + b + c) == 0)?true:false; 
    }
};
// @lc code=end

