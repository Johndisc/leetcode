//
// Created by 58253 on 2022/12/26.
//

#ifndef LEETCODE_N83_H
#define LEETCODE_N83_H
#include "global.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return nullptr;
        ListNode *p, *q;
        p = head;
        while (p->next) {
            if (p->val == p->next->val)
                p->next = p->next->next;
            else
                p = p->next;
        }
        return head;
    }
};
#endif //LEETCODE_N83_H
