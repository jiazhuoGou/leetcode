/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
/**
 * @brief 应该是算当前排列的逆序数，逆序数是从0开始,1234的逆序数就是0
 * 然后判断逆序数如果 = nums.size() - 1，
 *                  那么就找出比第一个数大1的数作首元素，其他元素从小到大排序
 *              如果 = nums.size() 
 *                  那么直接从小到大排序，回到起始排列
 *              如果是其他情况
 *              上述分析无效，看的官方解释，找一个较小的大数跟一个差最小的小数交换
 *                  
 * @param nums 排列 
 */
    void nextPermutation(vector<int>& nums) {
        // 从左往右找，找到一个不是降序的第一个数
        int left = -1, right = 0;
        int i = nums.size() - 2;
        for ( ; i >= 0 && nums[i] >= nums[i+1]; i-- );
        left = i;
        if(left >= 0)
        {// 说明找到这种升序,继续找比他的第一个数
            int j = nums.size() - 1;
            for( ; j >= 0 && nums[j] <= nums[left]; j--);
            right = j;
            swap(nums[left], nums[right]);
        }
        // 说明没找到
        reverse(nums.begin() + left + 1,nums.end());

    }



    int getCurInvNum(vector<int>& nums) 
    {   // 求当前排列的逆序数
        int cnt = 0;
        for(int i  = 0; i < nums.size() - 1; i++)
        {   // i是控制次数
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(nums[i] > nums[j])
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }

    int getMaxInvNum(int length)
    {   // 求这个数列的最大逆序数
        if(length == 1)
        {
            return 0;
        }
        return getMaxInvNum(length - 1) + length - 1;
    }   
};
// @lc code=end

