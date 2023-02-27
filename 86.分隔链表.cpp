/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head)
            return head;

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *base;
        ListNode *head2;
        bool flag = true;
        for (base = dummy; base->val < x; base = base->next)
        {
            if (flag && base->next && base->next->val == x)
            {
                head2 = base;
                flag = false;
            }
        }
        
        cout << head2->val << endl;
        ListNode *prev = base;
        ListNode *cur = prev->next;
        
        while (cur)
        {
            if (cur->val < x)
            {   // 要把它放在头节点后面
                prev->next = cur->next;
                cur->next = head2->next;
                head2->next = cur;
                cur = prev->next;
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }



        // 找到第一个比x大的节点，再去遍历，把所有小于的放在该节点之前
    return dummy->next;
    }   
};
// @lc code=end

