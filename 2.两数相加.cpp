/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 直接先找一个最长的出来，依次相加，注意进位,时间复杂度O(n)
        
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *h2;
        ListNode *h1;
        int carry = 0; // 存放进位
        
        int cnt1 = 0, cnt2 = 0;
        while(p1)
        {
            cnt1++;
            p1 = p1->next;
        }
        while(p2)
        {
            cnt2++;
            p2 = p2->next;
        }

        // 以l2为准,短的就交换
        if(cnt1 > cnt2)
        {   // 以p1, p2为准,p2永远是长的那条
            p1 = l2;
            h1 = l2;
            p2 = l1;
            h2 = l1;    
        }
        else
        {
            p1 = l1;
            p2 = l2;
            h1 = l1;
            h2 = l2;
        }

        while (p1)  // p1是短的, 所以p1会先完
        {
            if (p1->val + p2->val > 9)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            p2->val = (p1->val + p2->val > 9)?p1->val + p2->val - 10:p1->val + p2->val;
            if(p2->next == nullptr)
            {   // 这里是确保一样长有进位
                if (carry == 1)
                {
                    ListNode *tmp = new ListNode(carry);
                    p2->next = tmp;
                }
            }
            else
            {
                (p2->next)->val += carry;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        //  说明短的完了,判断是否带进位
        carry = 0;
        while(p2)
        {
            if(p2->val > 9)
            {
                p2->val -= 10;
                carry = 1;
            }
            if(p2->next == nullptr)
            {
                if (carry == 1)
                {
                    ListNode *tmp = new ListNode(carry);
                    p2->next = tmp;
                }
            }
            else
            {
                (p2->next)->val += carry; 
            }
            p2 = p2->next;
            carry = 0;
        }
        return h2;
    }
};
// @lc code=end

