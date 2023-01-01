//
// Created by 58253 on 2023/1/1.
//

#ifndef LEETCODE_N92_H
#define LEETCODE_N92_H
#include "global.h"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head->next)
            return head;
        ListNode *dummy = new ListNode;
        dummy->next = head;
        ListNode *x, *y, *z, *first;
        first = dummy;
        for (int i = 0; i < left - 1; ++i)
            first = first->next;
        x = first->next;
        y = x->next;
        for (int i = left; i < right; ++i) {
            z = y->next;
            y->next = x;
            x = y;
            y = z;
        }
        first->next->next = y;
        first->next = x;
        return dummy->next;
    }
};
#endif //LEETCODE_N92_H
