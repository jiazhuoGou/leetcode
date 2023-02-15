/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        vector<int> V;
        inorderTraversal(root, V);
        for (int i = 1; i < V.size(); i++) 
        {
            if (V[i] <= V[i-1])
            {
                return false;
            }
        }
        return true;
    }

    void inorderTraversal(TreeNode *root, vector<int> &V)
    {
        if (!root)
        {
            return;
        }
        inorderTraversal(root->left,V);
        V.push_back(root->val);
        inorderTraversal(root->right, V);
    }

    void print(vector<int> V)
    {
        for (vector<int>::iterator it = V.begin(); it != V.end(); it++)
        {
            cout << *it << " ";
        }
        cout << "\n";
    }
};
// @lc code=end

