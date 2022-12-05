//
// Created by 58253 on 2022/12/4.
//

#ifndef LEETCODE_N24_H
#define LEETCODE_N24_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *newhead = head->next, *cur = head, *p, *q, *temp;
        temp = head->next->next;
        head->next->next = head;
        head->next = temp;
        while (cur->next) {
            p = cur->next;
            q = cur->next->next;
            if (!q)
                break;
            temp = q->next;
            q->next = p;
            p->next = temp;
            cur->next = q;
            cur = p;
        }
        return newhead;
    }
};
#endif //LEETCODE_N24_H
