#include <iostream>
#include <vector>

using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>> &mat);
void print(vector<vector<int>> mat);
void print(vector<int> list);

int main(void)
{
    vector<vector<int>> mat{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    


    return 0;
}

vector<int> findDiagonalOrder(vector<vector<int>> &mat)
{
    vector<int> res;
    int row = mat.size();   // 行数
    int col = mat[0].size(); //列数
    int step = 0;   // 步长为偶数向下，步长为基数向上
    res.push_back(mat[0][0]);
    for ( ; step <= row; step++) 
    {   // step - 2为长的斜线
        int numDiagonal = 2; // 控制每个斜线的长度，翻过最长的对角线(行数)，就开始减1
        if(step % 2 == 0)
        {   // 向下
            for( int i = 0, j = step + 1; i < numDiagonal; i++)
            {
                
            }
        }
        else
        {   // 向上遍历

        }
    }



    return res;
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

void print(vector<int> list)
{
    for (vector<int>::iterator it = list.begin(); it != list.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
}