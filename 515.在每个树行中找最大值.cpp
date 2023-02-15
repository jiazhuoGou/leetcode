/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 用栈的思想,层序遍历
    vector<int> largestValues(TreeNode* root) {

        int queueSize = 0;  // 记录每层的个数
        queue<TreeNode*> q;
        queue<TreeNode*> tmp;
        queue<TreeNode*> tmp2;
        vector<int> V;
        vector<int> res;
        if (!root)
        {
            return res;
        }

        q.push(root);
        while (!q.empty())
        {
            queueSize = q.size();
            for (int i = 0; i < queueSize; i++)
            {   // 先把每一层弹出来，再选最大的，再把下一层加进来
                TreeNode *p = q.front();
                cout << " " << p->val;
                V.push_back(p->val);
                tmp.push(p);
                q.pop(); 
            }
            cout << "\n";
            res.push_back(getMax(V));
            for (int i = 0; i < queueSize; i++)
            { // 把下一层加进来
                TreeNode *p = tmp.front();
                if (p->left)
                {
                    q.push(p->left);
                }
                if (p->right)
                {
                    q.push(p->right);
                }
                tmp.pop();
            }
            V.clear();
        }
        return res;
    }

    
    void clear(queue<TreeNode*>& q) {
        queue<TreeNode*> empty;
        swap(empty, q);
    }

    int getMax(vector<int> V)
    {
        int max = V[0];
        for (auto v : V)
        {
            if (v > max)
            {
                max = v;
            }
        }
        return max;
    }
};
// @lc code=end

