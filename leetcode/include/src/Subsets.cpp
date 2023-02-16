#include <iostream>
#include <vector>

using namespace std;

void selfAdd(vector<int> &list, int cnt, int total);
vector<vector<int>> subsets(vector<int> &nums);
int pow(int x, int y);

int main(void)
{
    vector<int> nums{1, 2, 3};
    subsets(nums);
    cout << "end" << endl;
    return 0;
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> kongji;
    res.push_back(kongji);
    int total = pow(2, nums.size());
    int cnt = total;
    vector<int> binary(nums.size());

    if (nums.size() == 0)
        return res;

    // 先走一步, 把最后一个元素先加进来
    vector<int> first;
    first.push_back(nums[nums.size() - 1]);
    res.push_back(first);
    if (nums.size() == 1)
        return res;

    // 下面的操作必须保证nums长度大于2
    binary[binary.size() - 2] = 1; // 此时是0000010
    cnt = 2;                       // 方便转化二进制数组

    /* 二进制数组每加一次，就找到哪一项为1的，就把数加进来*/
    vector<int> tmp;
    for (int i = 0; i < total - 2; i++)
    {
        for (int j = binary.size() - 1; j >= 0; j--)
        {
            if (binary[j] == 1)
            {
                tmp.push_back(nums[j]);
            }
        }
        cout << i << " : ";
            for(int i = 0; i < tmp.size(); i++)
            {
                cout << " " << tmp[i];
            }
            cout << "\n";
        res.push_back(tmp);
        tmp.clear();
        // 二进制数组自加
        cnt++;
        selfAdd(binary, cnt);
    }
    return res;
}

int pow(int x, int y)
{
    int sum = 1;
    for (int i = 0; i < y; i++)
        sum *= x;
    return sum;
}

void selfAdd(vector<int> &list, int cnt, int total)
{
    if(cnt == total)
        return;
    for (int i = 0; i < list.size(); i++)
    {
        list[i] = 0;
    }
    int i = cnt, j = list.size() - 1;
    while (i != 0)
    {
        list[j--] = i % 2;
        i /= 2;
    }
    /*
    for (int i = 0; i < list.size(); i++)
    {
        cout << " " << list[i];
    }*/
    cout << "\n";
}