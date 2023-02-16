/*
 * @lc app=leetcode.cn id=2341 lang=cpp
 *
 * [2341] 数组能形成多少数对
 */

// @lc code=start
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> res(2);
        int count = 0;
        int temp = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }
        for (unordered_map<int, int>::iterator itr = map.begin(); itr != map.end(); itr++)
        {
            if (itr->second >= 2)
            {
                temp = itr->second / 2;
                count += temp * 2;
                res[0] += temp;
            }
        }
        res[1] = nums.size() - count;
        cout << res[0] << " " << res[1] << endl;

        return res;
    }

    void quick_sort(vector<int> &nums, int low, int high)
    {
        if (low < high)
        {
            int base = partition(nums, low, high);
            quick_sort(nums, low, base - 1);
            quick_sort(nums, base + 1, high);
        }
    }

    int partition(vector<int> &nums, int low, int high)
    {
        int x = nums[low];
        while (low < high)
        {
            while (low < high && nums[high] >= x)
                high--;
            nums[low] = nums[high];
            while (low < high && nums[low] <= x)
                low++;
            nums[high] = nums[low];
        }
        nums[low] = x;
        return low;
    }

        void print(vector<int> list)
{
    for (vector<int>::iterator it = list.begin(); it != list.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
}
};
// @lc code=end

