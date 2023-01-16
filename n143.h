//
// Created by 58253 on 2023/1/14.
//

#ifndef LEETCODE_N143_H
#define LEETCODE_N143_H
#include "global.h"

class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode *> lv;
        while (head) {
            lv.push_back(head);
            head = head->next;
        }
        int i = 0, j = lv.size() - 1;
        while (i < j) {
            lv[i]->next = lv[j];
            lv[j]->next = lv[i + 1];
            i++;
            j--;
        }
        if (i == j)
            lv[i]->next = nullptr;
        else
            lv[j + 1]->next = nullptr;
    }
};
#endif //LEETCODE_N143_H
