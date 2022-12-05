//
// Created by 58253 on 2022/12/4.
//

#ifndef LEETCODE_N23_H
#define LEETCODE_N23_H

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
    ListNode *mergeOne(ListNode *a, ListNode *b) {
        if (a == nullptr)
            return b;
        if (b == nullptr)
            return a;
        ListNode *head, *cur;
        if (a->val < b->val) {
            head = a;
            a = a->next;
        }
        else {
            head = b;
            b = b->next;
        }
        cur = head;
        while (a != nullptr && b != nullptr) {
            if (a->val <= b->val) {
                cur->next = a;
                cur = a;
                a = a->next;
            }
            else {
                cur->next = b;
                cur = b;
                b = b->next;
            }
        }
        if (a == nullptr)
            cur->next = b;
        else
            cur->next = a;
        return head;
    }

    ListNode *merge(vector<ListNode *> &lists, int bpos, int epos) {
        if (bpos == epos)
            return lists[bpos];
        if (bpos == epos - 1)
            return mergeOne(lists[bpos], lists[epos]);
        ListNode *left, *right;
        left = merge(lists, bpos, (bpos + epos) / 2);
        right = merge(lists, (bpos + epos) / 2 + 1, epos);
        return mergeOne(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        return merge(lists, 0, lists.size() - 1);
    }
};
#endif //LEETCODE_N23_H
