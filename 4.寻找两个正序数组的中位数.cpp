/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2023-02-17 15:44:10
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2023-02-17 16:09:31
 * @FilePath: \leetcode\4.寻找两个正序数组的中位数.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int m = nums1.size();
        int n = nums2.size();
        if (total & 0x01)
        {
            return find_kth(&nums1, m, &nums2, n, total / 2 + 1);
        }
        else
        {
            return (find_kth(&nums1, m, &nums2, n, total / 2) + find_kth(0, m, 0, n, total / 2 + 1)) / 2.0;
        }
    }

    // k代表第k大的数
    /**
     * @brief 递归终止条件 
     *          如果nums1， nums2为空，
     *          如果k = 1 返回nums1和nums2最小的数
     *          
     * @param pa 
     * @param m nums1指针还能动几步
     * @param pb 
     * @param n nums2指针还能动几步
     * @param k 第k大
     * @return int 
     */
    int find_kth(vector<int> *pa, int m, vector<int> *pb, int n, int k)
    {
        return 0;
    }
};
// @lc code=end

