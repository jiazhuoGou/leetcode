/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2022-08-09 14:43:21
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2022-08-09 15:08:35
 * @FilePath: \leetcode\1413.逐步求和得到正数的最小值.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// @lc code=start
class Solution {
public:
    
    int minStartValue(vector<int>& nums) {
        vector<int> prefix(nums + 1);
        int startValue = 0, sum = 0;
        for (int i = 1; i < nums.size(); ++i) 
        {
            sum += nums[i-1];
            prefix[i] = sum;
        }

        for (auto num : prefix)
        {
            cout << num << endl;
        }


        return startValue;

    }
};
// @lc code=end

