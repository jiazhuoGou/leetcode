/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2022-08-05 15:40:54
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2022-08-05 15:49:32
 * @FilePath: \leetcode\623.在二叉树中增加一行.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
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
 *     TreeNode(int x,  TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        int level = 0;
        TreeNode *p = root;
        queue<TreeNode *> q;
        vector<TreeNode *> levelNodes;
        q.push(p);
        while (!q.empty())
        {
            
        }



        return root;
    }
};
// @lc code=end

