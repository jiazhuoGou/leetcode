/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return head;

        ListNode *dummy = NULL;
        dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* const head2 = dummy;
        ListNode *prev = head2->next;
        ListNode *cur = prev->next;
        
        // 头插法，head->next->next = 新的第一节点，新第一节点next=原第一节点，还要改一个
        // 这样就不用三个指针
        while (cur)
        {   // cur指向的节点始终要变成第一节点
            prev->next = cur->next; // 先要记住后面的
            cur->next = head2->next;
            head2->next = cur;
            cur = prev->next;
        }



        return dummy->next;
    }
};
// @lc code=end

