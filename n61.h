//
// Created by 58253 on 2022/12/21.
//

#ifndef LEETCODE_N61_H
#define LEETCODE_N61_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return nullptr;
        ListNode *p, *q;
        p = head;
        q = head;
        int num = 0;
        for (int i = 0; i < k; ++i) {
            q = q->next;
            num++;
            if (!q) {
                q = head;
                k = k % num;
                i = 0;
                continue;
            }
        }
        while (q->next) {
            q = q->next;
            p = p->next;
        }
        q->next = head;
        head = p->next;
        p->next = nullptr;
        return head;
    }
};
#endif //LEETCODE_N61_H
