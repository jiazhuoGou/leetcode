/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2022-10-24 19:27:23
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2022-10-24 19:30:41
 * @FilePath: \leetcode\src\test.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include <vector>

using namespace std;

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

void quickSort(vector<int> &arr, int low, int high)
    {
        if (low < high)
        {
            int base = partition(arr, low, high);
            quickSort(arr, low, base - 1);
            quickSort(arr, base + 1, high);
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


    int main(void)
    {
        vector<int> arr {5,10,3,6,9};
        quickSort(arr, 0, 4);
        print(arr);
        return 0;
    }