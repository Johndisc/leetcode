//
// Created by 58253 on 2023/1/16.
//

#ifndef LEETCODE_N148_H
#define LEETCODE_N148_H
#include "global.h"

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *fast, *slow;
        fast = slow = head;
        while (fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *right = sortList(slow->next);
        slow->next = nullptr;
        ListNode *left = sortList(head);
        ListNode *p = new ListNode, *q = p;
        while (left || right) {
            if (!left) {
                p->next = right;
                break;
            }
            if (!right) {
                p->next = left;
                break;
            }
            if (left->val < right->val) {
                p->next = left;
                left = left->next;
            }
            else {
                p->next = right;
                right = right->next;
            }
            p = p->next;
        }
        return q->next;
    }
};
#endif //LEETCODE_N148_H
