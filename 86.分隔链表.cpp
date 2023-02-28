/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2023-02-27 20:00:57
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2023-02-28 11:19:57
 * @FilePath: \leetcode\86.分隔链表.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
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
        if (!head || !head->next)
            return head;

        ListNode *dummy = new ListNode(-201);   // 头节点一定是最小的
        dummy->next = head;

        ListNode *temp;     // 第一个比他大的节点,后面的小数都要插到它前面
        for (temp = dummy; temp && temp->val < x; temp = temp->next);
        if (!temp)
        { // 说明没有比x大的数直接返回
            return head;
        }
        ListNode *head2;    // 它是要把后面小的数插到前面来的头节点
        for (head2 = dummy; head2->next && head2->next->val != temp->val; head2 = head2->next);
        ListNode *prev = temp;
        ListNode *cur = NULL;
        if (prev->next)
        {
            cur = prev->next;
        }

        bool flag = false;
        while (cur)
        {
            if (cur->val < x)
            {   // 要把它放在头节点后面
                prev->next = cur->next;
                cur->next = head2->next;
                head2->next = cur;
                cur = prev->next;
                flag = true;
            }
            else
            {
                prev = cur;
                cur = cur->next;
                flag = false;
            }

            if (flag)
            {
                head2 = head2->next;
            }
        }
        // 找到第一个比x大的节点，再去遍历，把所有小于的放在该节点之前
    return dummy->next;
    }   
};
// @lc code=end

