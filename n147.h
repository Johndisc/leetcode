//
// Created by 58253 on 2023/1/16.
//

#ifndef LEETCODE_N147_H
#define LEETCODE_N147_H
#include "global.h"

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head)
            return nullptr;
        ListNode *p, *q, *dummy;
        dummy = new ListNode;
        dummy->next = head;
        q = head;
        while (q->next) {
            p = dummy;
            while (p->next->val < q->next->val && p != q)
                p = p->next;
            if (p == q) {
                q = q->next;
                continue;
            }
            ListNode *temp = q->next->next;
            q->next->next = p->next;
            p->next = q->next;
            q->next = temp;
            p = dummy->next;
        }
        return dummy->next;
    }
};
#endif //LEETCODE_N147_H
