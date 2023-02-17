/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2023-02-15 15:06:58
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2023-02-17 14:20:49
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
        if (nums.size() <= 2)
            return nums.size();
        int index = 2;  // index之前都是处理好的，index是即将被覆盖的那一位，i遍历剩下的数
        for (int i = 2; i < nums.size(); i++)
        {   // 每次i与index-2相比, 这是一个排好序的数组，那说明中间这一个也相同
            // 那么就有三个一样的了，那么i这一位必须被新数覆盖或者动下去不计入长度
            if (nums[i] != nums[index - 2])
            {   // 它与前2个数相比是新数，肯定会被保留，所以马上覆盖
                nums[index++] = nums[i];    
            }
        }
        cout << index << endl;
        for (auto num : nums)
        {
            cout << " " << num;
        }
        return index;
    }

    /**
     * @brief 将上面代码的2改成其他数也可以实现
     * 
     */
};
// @lc code=end

