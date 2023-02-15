/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    // 思想就是不断分割中序，后序数组
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0)
        {
            return nullptr;
        }
        return traverseTree(inorder, postorder);
    }

    TreeNode *traverseTree(vector<int>& inorder, vector<int>& postorder)
    {   // 关键代码
        if (postorder.size() == 0)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(postorder[postorder.size()-1]);
        if (postorder.size() == 1)
        { // 说明再找新父节点的时候只有一个，那么他其实就是叶子节点了，直接返回
            return root;
        }

        /**
         * @brief 把中序遍历分成两半，左边是父节点的左子树，右边是父节点的右子树
         * 再中序数组找到父节点得到其index，-1就是左子树的最后一个，+1就是右子树的第一个
         * 然后就新建4个数组来接他们
         */
        int inorderDivsionIndex = 0;
        for (; inorder[inorderDivsionIndex] != root->val; inorderDivsionIndex++)
        vector<int> leftInorderList, rightInorderList, leftPostorderList, rightPostorderList;
        return NULL;
        
    }
};
// @lc code=end

