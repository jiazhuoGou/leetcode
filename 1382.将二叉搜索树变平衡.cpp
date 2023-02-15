/*
 * @lc app=leetcode.cn id=1382 lang=cpp
 *
 * [1382] 将二叉搜索树变平衡
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
    TreeNode* balanceBST(TreeNode* root) {
        int res = postorder(root);
        if (res >= 0)
        { // 是平衡的
            return root;
        }

        // 不是平衡二叉树，再来修改
        return root;
    }

    int postorder(TreeNode *root)
    { // 先判断他是不是平衡
        if (!root)
        {
            return 0;
        }
        int leftHeight = postorder(root->left);
        int rightHeight = postorder(root->right);
        if (abs(leftHeight - rightHeight) > 1 || leftHeight == -1 || rightHeight == -1)
        {   // 说明这个结点就不是平衡的
            return -1;
        }
        else
        {
            return max(leftHeight, rightHeight) + 1;
        }
    }
};
// @lc code=end

