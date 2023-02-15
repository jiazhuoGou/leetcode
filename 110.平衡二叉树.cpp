/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
     // 思路跟求二叉树深度类似，注意递归终止条件
     // 左右子树高度差大于1
        bool isBalanced(TreeNode* root) {
        
        int res = postorder(root);
        if (res >= 0)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    int postorder(TreeNode *root)
    {
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

