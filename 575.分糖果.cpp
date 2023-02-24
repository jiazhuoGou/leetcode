/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2023-02-24 20:26:48
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2023-02-24 20:35:13
 * @FilePath: \leetcode\575.分糖果.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */

// @lc code=start
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        const int n = candyType.size() / 2;
        int res = 0;
        unordered_map<int, int> umap;
        for (int i = 0; i < candyType.size(); ++i)
        {
            umap[candyType[i]]++;
        }

        
        return n >= umap.size()?umap.size():n;
    }
};
// @lc code=end

