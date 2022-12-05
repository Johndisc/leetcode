//
// Created by 58253 on 2022/12/4.
//

#ifndef LEETCODE_N25_H
#define LEETCODE_N25_H

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head)
            return head;
        ListNode *newhead = head;
        int cnt = 1;
        while (cnt < k) {
            newhead = newhead->next;
            cnt++;
            if (newhead == nullptr)
                return head;
        }
        ListNode *p, *q, *temp, *cur = head, *begin = nullptr;
        while (cur) {
            p = cur;
            q = cur->next;
            cnt = 1;
            while (cnt < k) {
                cur = cur->next;
                cnt++;
                if (cur == nullptr)
                    return newhead;
            }
            if (begin)
                begin->next = cur;
            begin = p;
            cur = cur->next;
            p->next = cur;
            cnt = 1;

            while (cnt < k) {
                temp = q->next;
                q->next = p;
                p = q;
                q = temp;
                cnt++;
            }
        }
        return newhead;
    }
};
#endif //LEETCODE_N25_H
