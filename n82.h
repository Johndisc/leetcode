//
// Created by 58253 on 2022/12/26.
//

#ifndef LEETCODE_N82_H
#define LEETCODE_N82_H
#include "global.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;
        ListNode *p, *q;
        int last;
        bool same = false;
        p = head;
        q = head->next;
        last = p->val;
        while (q) {
            if (q->val == last) {
                q = q->next;
                same = true;
            }
            else if (same) {
                head = q;
                p = head;
                last = q->val;
                q = head->next;
                same = false;
            }
            else
                break;
        }
        if (same)
            return nullptr;
        if (!q)
            return head;
        last = q->val;
        q = q->next;
        same = false;
        while (q) {
            if (q->val == last) {
                same = true;
            }
            else if (same) {
                p->next = q;
                same = false;
            }
            else {
                p = p->next;
            }
            last = q->val;
            q = q->next;
        }
        if (same)
            p->next = nullptr;
        return head;
    }
};
#endif //LEETCODE_N82_H
