/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return nullptr;
        ListNode *h = new ListNode(0, head);
        ListNode *p = h->next;
        int cnt = 0;
        for(; p != nullptr; p = p->next) cnt++;
        cout <<"总数" << cnt;
        p = h;
        for(int i = 0; i < (cnt - n) ; p = p->next, i++);
        // 此时的p就是待删节点的前一个
        cout << p->val;
        if(p->next == nullptr)
            p->next = nullptr;
        else
            p->next = (p->next)->next;
        return h->next;
    }
};
// @lc code=end

