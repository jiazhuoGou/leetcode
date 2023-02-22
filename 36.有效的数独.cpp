/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2023-02-22 18:50:37
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2023-02-22 19:54:22
 * @FilePath: \leetcode\36.有效的数独.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 朴素思想
        vector<bool> used(9, false);
        for (int i = 0; i < board.size(); i++)
        {
            // 先检查每行
            setup_fasle(used);
            for (auto use : used)
            {
                cout << " " << use;
            }
            cout << "  Error " <<  "\n";
            for (int j = 0; j < board.size(); j++)
            {
                if ( !check(board[i][j], used) )
                {
                    cout << "Error: " << board[i][j] << " " << i << " " << j << endl;
                    return false;
                }
            }

            // 检查每列
            setup_fasle(used);
            for (auto use : used)
            {
                cout << " " << use;
            }
            cout << "  Error1 " <<  "\n";
            for (int j = 0; j < board.size(); j++)
            {
                if ( !check(board[i][j], used) )
                {
                    cout << "Error2: " << board[i][j] << " " << i << " " << j << endl;
                    return false;
                }
            }
        }

        // 检查九宫格
        for (int i = 0; i < 7; i += 3)
        {
            for (int j = 0; j < 7; j += 3)
            {
                setup_fasle(used);
                for (auto use : used)
            {
                cout << " " << use;
            }
            cout << "  Error3 " <<  "\n";
                if (!check(board[i][j], used) || !check(board[i][j+1], used) || !check(board[i][j+2], used) 
                    || !check(board[i+1][j], used) || !check(board[i+1][j+1], used) || !check(board[i+1][j+2], used)
                    || !check(board[i+2][j], used) || !check(board[i+2][j+1], used) || !check(board[i+2][j+2], used)               
                )
                {
                    cout << "Error3: " << board[i][j] << " " << i << " " << j << endl;
                    return false;
                }
            }
        }
        return true;
    }

    bool check(char ch, vector<bool> &used)
    {
        if (ch == '.')
        {
            return true;
        }
        else if (used[ch - '1'])
        {   // 被用过
            return false;
        }
        used[ch - '1'] = true;
        return true;
    }

    void setup_fasle(vector<bool> &used)
    {
        for (auto use : used)
        {
            use = false;
        }
    }
};
// @lc code=end

