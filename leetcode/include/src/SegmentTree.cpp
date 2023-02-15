#include <iostream>
#include <vector>

using namespace std;

void buildTree(vector<int> &arr, vector<int> &tree, int node, int start, int end);
void updateTree(vector<int> &arr, vector<int> &tree, int node, int start, int end, int index, int val);
int queryTree(vector<int> &arr, vector<int> &tree, int node, int start, int end, int left, int right);

#define MAX_LEN 50

int main(void)
{

    vector<int> arr{1, 3, 5, 7, 9, 11};
    vector<int> tree(MAX_LEN); // 用数组模拟线段树
    int len = arr.size() - 1;

    buildTree(arr, tree, 0, 0, len);
    updateTree(arr, tree, 0, 0, len, 4, 6);
    for (int i = 0; i < tree.size(); ++i)
    {
        cout << tree[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << "\n" << queryTree(arr, tree, 0, 0, len, 2, 5 ) << endl;

    return 0;
}

void buildTree(vector<int> &arr, vector<int> &tree, int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
    }
    else
    {
        int mid = (start + end) / 2;
        int leftNode = 2 * node + 1;
        int rightNode = 2 * node + 2;
        buildTree(arr, tree, leftNode, start, mid);
        buildTree(arr, tree, rightNode, mid + 1, end);
        tree[node] = tree[leftNode] + tree[rightNode];
    }
}

void updateTree(vector<int> &arr, vector<int> &tree, int node, int start, int end, int index, int val)
{
    if (start == end)
    {
        arr[index] = val;
        tree[node] = val;
    }
    else
    {
        int mid = (start + end) / 2;
        int leftNode = 2 * node + 1;
        int rightNode = 2 * node + 2;
        if (index >= start && index <= mid)
        {
            updateTree(arr, tree, leftNode, start, mid, index, val);
        }
        else
        {
            updateTree(arr, tree, rightNode, mid + 1, end, index, val);
        }
        tree[node] = tree[leftNode] + tree[rightNode];
    }
}

// 闭区间
int queryTree(vector<int> &arr, vector<int> &tree, int node, int start, int end, int left, int right)
{
    cout << "start: " << start << " end: " << end << endl;
    if (right < start || left > end)
    { // 如果不在计算范围内，return 0
        return 0;
    }
    else if (left <= start && end <= right)
    {
        return tree[node];
    }
    else if (start == end)
    { // 正好找到这个区间
        return tree[node];
    }
    else
    {
        int mid = (start + end) / 2;
        int leftNode = 2 * node + 1;
        int rightNode = 2 * node + 2;
        int sumLeft = queryTree(arr, tree, leftNode, start, mid, left, right);
        int sumRight = queryTree(arr, tree, rightNode, mid + 1, end, left, right);
        return sumRight + sumLeft;
    }
}