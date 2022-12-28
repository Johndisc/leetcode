//
// Created by 58253 on 2022/12/28.
//

#ifndef LEETCODE_N86_H
#define LEETCODE_N86_H
#include "global.h"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head)
            return head;
        ListNode *p, *q, *dummyhead, *mid;
        dummyhead = new ListNode;
        dummyhead->next = head;
        dummyhead->val = -200;
        p = q = dummyhead;
        while (q && q->val < x) {
            p = q;
            q = q->next;
        }
        if (!q)
            return dummyhead->next;

        while (q->next) {
            if (q->next->val < x) {
                mid = q->next;
                q->next = mid->next;
                mid->next = p->next;
                p->next = mid;
                p = mid;
            }
            else
                q = q->next;
        }
        return dummyhead->next;
    }
};
#endif //LEETCODE_N86_H
