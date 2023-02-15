/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
class Solution
{
public:
    // 层序遍历，遇到的都入栈，然后判断出栈结点的高度是否等于1，等于1说明是最后一层，然后第一个找到的就是最左边的
    // 求高度时间复杂度是 O(n),
    int findBottomLeftValue(TreeNode *root)
    {
        int h = getBitreeHeight(root);
        int curLevel = getNodeLevel(root, 2);
        int res = 0; 
        queue<TreeNode*> q; 
        
        /* 先将根节点入队 */
        q.push(root);
        while ( !q.empty() )
        {   // 队列里面不为空，就把队列的第一个元素弹出，把他的孩子入队
            // 因为要得到最左边的结点，所以入队的时候要先入右孩子，这样左孩子才能保证再最后
            TreeNode *p = q.front();
            if (p->right)
            {
                q.push(p->right);
            }
            if (p->left)
            {
                q.push(p->left);
            }
            res = p->val;
            q.pop();
        }

        return res;
    }

    int getNodeLevel(TreeNode *node, int target)
    { // 求二叉树中某一结点的层数, 这个要保证不能有重复
        if (!node)
        {
            return 0;
        }
        if (node->val == target)
        { // 说明找到这个结点，该节点记为第一层
            return 1;
        }
        int leftLevel = getNodeLevel(node->left, target);
        int rightLevel = getNodeLevel(node->right, target);
        if (leftLevel == 0 && rightLevel == 0)
        {
            return 0;
        }
        else
        {
            return leftLevel + rightLevel + 1;
        }
    }

    // 求二叉树的高度
    int getBitreeHeight(TreeNode *node)
    {

        if (!node)
        {
            return 0;
        }
        int leftHeight = getBitreeHeight(node->left);
        int rightHeight = getBitreeHeight(node->right);
        return max(leftHeight, rightHeight) + 1;
    }

    // 求某一结点的高度, 这个不是层数，我的思想是应该得到层数
    int getNodeHeight(TreeNode *node, int val, int &h)
    { // 这个叶子结点都是1，不是我要的
        if (!node)
        {
            return 0;
        }
        int leftHeight = getNodeHeight(node->left, val, h);
        int rightHeight = getNodeHeight(node->right, val, h);
        if (val == node->val)
        {
            h = max(leftHeight, rightHeight) + 1;
        }
        return max(leftHeight, rightHeight) + 1;
    }

    int max(int a, int b)
    {
        return a > b ? a : b;
    }
};
// @lc code=end
