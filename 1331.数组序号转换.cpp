/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2022-07-28 14:43:46
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2022-08-12 15:20:43
 * @FilePath: \leetcode\1331.数组序号转换.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2022-07-28 14:43:46
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2022-07-28 15:40:36
 * @FilePath: \leetcode\1331.数组序号转换.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=1331 lang=cpp
 *
 * [1331] 数组序号转换
 */

// @lc code=start
class Solution
{
public:
    // 用到map
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        vector<int> result(arr.size());
        vector<int> sortArr(arr);
        quickSort(sortArr, 0, sortArr.size()-1);
        
        unordered_map<int, int> map;
        for (vector<int>::iterator it = sortArr.begin(); it != sortArr.end(); it++)
        {
            if ( !map.count(*it) )
            { // 这个键没有
                map.insert(pair<int, int>(*it, map.size()+1));
            }
        }
        for (int i = 0; i < arr.size(); i++)
        {
            result[i] = map[arr[i]];
        }
        return result;
    }

    
    void quickSort(vector<int> &arr, int low, int high)
    {
        if (low < high)
        {
            int base = partition(arr, low, high);
            quickSort(arr, low, base - 1);
            quickSort(arr, base + 1, high);
        }
    }

    int partition(vector<int> &arr, int low, int high)
    {
        int x = arr[low];
        while (low < high)
        {
            while (high > low && arr[high] >= x)
                high--;
            arr[low] = arr[high];
            while (low < high && arr[low] <= x)
                low++;
            arr[high] = arr[low];
        }
        arr[low] = x;
        return low;
    }

};
// @lc code=end
