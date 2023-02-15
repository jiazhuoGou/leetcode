/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /**
         * @brief 将每一行最后一个数放入一个数组中，找出与目标值差值最小的
         * 然后判断是在这一行还是上一行或者下一行，在对每行搜索
         */
        int col = matrix[0].size(); // 列数
        vector<int> V;
        for (int i = 0; i < matrix.size(); i++)
        {
            V.push_back(matrix[i][col-1]);
        }
        int row = findMinimalDiff(V, target);   // 最接近的行
        cout << row << endl;
        

        return false;
    }

    int findMinimalDiff(vector<int> V, int target)
    {   // 找出差值绝对值最小的行
        int tmp = V[0] - target;
        int diff = (tmp > 0)?tmp:(tmp - 2 * tmp);
        int min = diff, index = 0; //  找出最小的一个
        cout << "差值" <<  diff << endl;
        for(int i = 1; i < V.size(); i++)
        {
            tmp = V[i] - target;    // 差值
            diff = (tmp > 0)?tmp:(tmp - 2 * tmp);   // 保证正数
            if (min > diff)
            {
                min = diff;
                index = i;
            }
            cout << "差值" << diff << endl;
        }

        return index;
    }

    int binarySearch(vector<int> V, int target)
    {   // 对某一行用二分查找，找到返回列数，否则返回-1
        int left = 0, right = V.size();
        int mid = 0;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (V[mid] == target)
            {
                cout << "一次行二分" << endl;
                return mid;
            }
            else if (V[mid] > target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        cout << "一次行二分" << endl;
        return -1;
    }

};
// @lc code=end

