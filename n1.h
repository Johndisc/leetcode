//
// Created by 58253 on 2022/5/27.
//

#ifndef LEETCODE_TWO_NUM_ADD_H
#define LEETCODE_TWO_NUM_ADD_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *last = nullptr, *tail, *head = nullptr;
        int a = 0, b = 0, c;
        int x, y;
        while (l1 != nullptr || l2 != nullptr) {
            x = l1 == nullptr ? 0 : l1->val;
            y = l2 == nullptr ? 0 : l2->val;
            b = (x + y + a) / 10;
            c = (x + y + a) % 10;
            a = b;
            tail = new ListNode(c);
            if(!head)
                head = tail;
            if(last)
                last->next = tail;
            last = tail;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        if (b == 1) {
            tail = new ListNode(b);
            last->next = tail;
        }
        return head;
    }
};

#endif //LEETCODE_TWO_NUM_ADD_H
