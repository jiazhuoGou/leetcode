/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
/**
 * @brief 每一行用一个vector，遍历字符串依次存储在每一行中,还要算出列数，以便构造一个矩阵
 *          时间复杂度, 空间复杂度
 * @param s 给定的字符串
 * @param numRows 指定的行数
 * @return string 返回的新顺序字符串
 */
    string convert(string s, int numRows) {
        if (numRows == 1)
        { // 保证行数为1的特殊情况
            return s;
        }
        
        // 这个列数有点搞人,会有很多空余空间, 并且下面这种情况必须保证行数大于1
        int numCols = (s.length() / (2 * numRows -2)) * (numRows - 1) + (numRows - 1);
        // 矩阵的初值是多少,都是'\0'，与c语言一样
        vector<vector<char> > matrix(numRows, vector<char>(numCols));   // 构建这么一个矩阵他有空隙
        // 返回字符串
        string ret;
        int i = 0, j = 0,  k = -1;
        int m, n;
        int flag = 1;
        for (i = 0; i < numCols && flag; i += numRows - 1)
        {   // 依次填数,从左往右开始, i还是列数，j是行数
            for (j = 0; j < numRows && flag; j++)
            {   // 这只是一整列都有的
                matrix[j][i] = s[++k];
                if(k >= s.length() - 1)
                {
                    flag = 0;
                }
            }
            // 填完一整列，开始填斜线
            n = i;
            m = j - 1; // 因为退出循环时还加了一次
            for (int a = 0; (a < numRows - 2) && flag; a++)
            {
                matrix[--m][++n] = s[++k];
                if (k >= s.length() - 1)
                {
                    flag = 0;
                }    
            }
        }

        for (vector< vector<char> >::iterator itr = matrix.begin(); itr != matrix.end(); itr++)
        {   // 在遍历一次，拼接字符串
            for (vector<char>::iterator it = itr->begin(); it != itr->end(); it++)
            {
                    if (*it != '\0')
                    {
                        ret.append(1, *it);
                    }
                    
            }
        }
        return ret;
    }
};
// @lc code=end

