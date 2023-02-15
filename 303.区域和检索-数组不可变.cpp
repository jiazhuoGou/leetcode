/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
public:
    // 前缀和，再开一个数组（大小加一），记录 0~i的和 
    int *preSum = nullptr;
    NumArray(vector<int>& nums) {
        // 构造函数，创建preSum数组
        preSum = new int[nums.size() + 1];
        preSum[0] = 0 ; // 占位，从1号位置开始
        // 分别填数，preSum数组的i-1号下标记录 原数组 0 ~ i 下标的和
        for (int i = 1; i < nums.size() + 1; i++)
        {
            preSum[i] = preSum[i-1] + nums[i-1];
        }

    }
    
    int sumRange(int left, int right) {
        return preSum[right + 1] - preSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

