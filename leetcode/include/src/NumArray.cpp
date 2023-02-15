/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2022-09-30 10:40:54
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2022-09-30 10:55:02
 * @FilePath: \leetcode\src\NumArray.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>

using namespace std;


class NumArray {
public:
    vector<int> *c;
    vector<int> *temp;

    NumArray(vector<int>& nums) {
        c = new vector<int>(nums.size()+1); // 从1开始
        temp = new vector<int>(nums);
        cout << "init" << endl;
        for (int i = 0; i < nums.size(); i++)
        {
            insert(i, nums[i]);
        }
    }

    void insert(int i, int val)
    {// 要改A[i]，就改c[i]，再依次往上改
        int index = i+1;
        while (index < c->size())
        {
            c->at(index) += val;
            cout << "update " << index  << "  " << c->at(index) << endl;
            index += lowbit(index); 
        }
    }
    
    void update(int index, int val) {
        int i = index + 1;
        if (i > 0 && i <= c->size())
        {
            c->at(i) -= temp->at(index);
            temp->at(i) = val;
        }
        while (i < c->size())
        {
            c->at(i) += val;
            i += lowbit(i);
        }
    }
    
    int sumRange(int left, int right) {
        int i = left, j = right + 1;
        int sum1 = 0, sum2 = 0;
        while (j > 0)
        {
            sum2 += c->at(j);
            j -= lowbit(j);
        }
        while (i > 0)
        {
            sum1 += c->at(i);
            i -= lowbit(i);
        }
        return sum2 - sum1;
    }

    int lowbit(int x)
    {
        return x & (-x);
    }
};


int main(void)
{
    vector<int> nums {1,3,5};
    NumArray  *obj = new NumArray(nums);

}
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */