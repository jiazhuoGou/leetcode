/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2022-10-31 15:03:16
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2022-10-31 16:04:21
 * @FilePath: \leetcode\784.字母大小写全排列.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        vector<vector<int>> bitmap(2, vector<int>(s.size()));
        string temp;
        int cols = 0, num = 0;
        for (int i = 0; i < s.size(); i++)
        {
            bitmap[0][i] = -1;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (isalpha(s[i]))
            {
                bitmap[0][cols++] = i;
            }   
        }
        for (int i = 0; i < s.size(); i++)
        {
            bitmap[1][i] = 0;
        }

        
        for (int i = 0; i < pow(2, cols); i++)
        {
            temp = s;
            for (int j = 0; j < cols; j++)
            {
                if (bitmap[1][j] == 0)
                {   // 小写
                    temp[bitmap[0][j]] = tolower(temp[bitmap[0][j]]);
                }
                else
                {   // 大写
                    temp[bitmap[0][j]] = toupper(temp[bitmap[0][j]]);
                }
            }
            res.push_back(temp);
            if (i < pow(2, cols)-1)
                selfadd(bitmap, cols, i+1);
            //print(bitmap);
        }
        
        
        
        return res;
    }

    int pow(int x, int cnt)
    {
        int sum = 1;
        for (int i = 0; i < cnt; i++)
        {
            sum *= x;
        }
        return sum;
    }

    /**
     * @brief 返回num的数字的二进制，cols是位数
     * 
     * @param arr 
     * @param cols 
     * @param num 
     */
    void selfadd(vector<vector<int>>& arr, int cols, int num)
    {
        int i = cols - 1;
        while (num != 0)
        {
            arr[1][i--] = num % 2;
            num /= 2;
        }
    }

    void print(vector<vector<int>> mat)
    {
        for (vector<vector<int>>::iterator itr = mat.begin(); itr != mat.end(); itr++)
        {
            for (vector<int>::iterator it = (*itr).begin(); it != (*itr).end(); it++)
            {
                cout << *it << " ";
            }
            cout << "\n";
        }
}
};
// @lc code=end

