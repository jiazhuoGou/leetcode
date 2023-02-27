/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(-1);
        dummy.next = head;

        ListNode *prev = &dummy;
        for ( int i = 0; i < left-1; ++i, prev = prev->next);
        ListNode* const head2 = prev;

        prev = head2->next;
        ListNode *cur = prev->next;
        cout << head2->val << " " << prev->val << " " << cur->val <<endl;
        for (int i = left; i < right; ++i)
        {
            prev->next = cur->next;
            cur->next = head2->next;
            head2->next = cur;
            cur = prev->next;
        }
        return dummy.next;
    }   
};
// @lc code=end

