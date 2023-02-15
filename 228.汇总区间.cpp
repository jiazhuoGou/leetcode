/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2022-10-20 19:42:08
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2022-10-21 19:40:06
 * @FilePath: \leetcode\228.汇总区间.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        // 还要注意负数
        vector<string> res;
        if (nums.size() == 0)
        {
            return res;
        }

        nums.push_back(nums[nums.size()-1]);
        string temp;
        int cnt = 0;
        for (int i = 0; i < nums.size()-1; i++) 
        { 
            if (cnt == 0 && nums[i+1] - nums[i] == 1)
            {
                temp += int_2_string(nums[i]);
                temp += "->";
                cnt++;
                continue;
            }
            else if (cnt != 0 && nums[i+1] - nums[i] == 1)
            {

            }
            else if (cnt != 0 && nums[i+1] - nums[i] != 1)
            {
                temp += int_2_string(nums[i]);
                res.push_back(temp);
                temp = "";
                cnt = 0;
            }
            else if (cnt == 0 && nums[i+1] - nums[i] != 1)
            {
                temp += int_2_string(nums[i]);
                res.push_back(temp);
                temp = "";
            }
        }
        return res;
    }
    
    /**
     * @brief int转string
     * 
     * @param num 
     * @return string 
     */
    string int_2_string(long num)
    {
        string ret, temp;
        if (num == 0)
        {
            return "0";
        }
        int flag = 0;
        if (num < 0)
        {
            flag = 1;
            num = num * (-1);
        }
        while (num != 0)
        {
            temp = char((num % 10) + '0') + temp;
            num /= 10;
        }
        if (flag == 1)
        {
            ret = '-' + temp;
            return ret;
        }
        return temp;
    }
};
// @lc code=end

