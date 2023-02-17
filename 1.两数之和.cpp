/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2023-02-17 16:38:30
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2023-02-17 17:08:30
 * @FilePath: \leetcode\1.两数之和.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    // hash
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            umap[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            const int temp = target - nums[i];
            if (umap.find(temp) != umap.end() && umap[temp] > i)
            {
                res.push_back(i);
                res.push_back(umap[temp]);
                break;
            }
        }
        return res;
    }
};
// @lc code=end

