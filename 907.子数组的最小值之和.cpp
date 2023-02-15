/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2022-10-28 18:03:56
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2022-10-28 18:32:03
 * @FilePath: \leetcode\907.子数组的最小值之和.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=907 lang=cpp
 *
 * [907] 子数组的最小值之和
 */

// @lc code=start
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int sum = 0;
        vector<int> binary(arr.size());
    
        
        for (int i = 1; i <= arr.size(); i++)
        {   //   i为子数组长度
            for (int j = 0; j < i; j++)
            {
                binary[j] = 1;
                sum += arr[j];
            }
            for (int j = 0; j < binary.size(); j++)
            {
                binary[j] = 0;
            }
            for (int j = 0; j < arr.size() - i; j++)
            {   // j为长度i的子数组的个数
                // 对二进制数组每一此将最左边的移到最右边的右边，得到的连续的1，然后这些下标就是要加的。找个最小的                
                move_binary(binary, i);
                sum += get_binary_min(arr, binary, i);
            }
            for (int j = 0; j < binary.size(); j++)
            {
                binary[j] = 0;
            }
        }

        return sum;
    }

    /**
     * @brief 
     * 
     * @param arr 
     * @param binary 
     * @param len 子数组长度
     * @return int 
     */
    int get_binary_min(vector<int> arr, vector<int> binary, int len)
    {   
        int min = 0, i = 0;
        for ( ; binary[i] != 1; i++);
        for (int j = 0, k = i; j < len; j++, k++)
        {
            if (min > arr[k])
            {
                min = arr[k];
            }
        }
        return min;
    }

    void move_binary(vector<int> &binary, int len)
    {
        int i = 0, j = 0;
        for ( ; binary[i] != 1; i++);
        j = i;
        for ( ; binary[j] == 1; j++);
        binary[j] = 1;
        binary[i] = 0;
        print(binary);
    }

    void print(vector<int> arr)
    {
        for (auto entry : arr)
        {
            cout << entry << " ";
        }
        cout << "\n";
    }
};
// @lc code=end

