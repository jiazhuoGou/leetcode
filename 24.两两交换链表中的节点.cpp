/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if (!head)
        {
            return nullptr;
        }
        
        ListNode *h = new ListNode(0, head);    // 转化为有头节点的链表
        // 要判断当前位的下下位有没有数据，避免奇偶个数问题
        ListNode *p = h->next;
        if(!(p->next))
            {
                return h->next;
            }
            while(p->next)
            {
                if (p->next)
                {
                    swap(p->val, (p->next)->val);
                    p = p->next;
                    if( !(p->next))
                    {
                        break;
                    }
                    p = p->next;
                }
            }
        return h->next;
    }
    void swap(int &a, int &b)
    {
        a = a ^ b;
        b = a ^ b;  // b = a ^ b ^ ^b
        a = a ^ b;  // a = a ^ b ^ a 
    }
};
// @lc code=end

