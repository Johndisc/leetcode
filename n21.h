//
// Created by 58253 on 2022/8/15.
//

#ifndef LEETCODE_N21_H
#define LEETCODE_N21_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <stack>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        ListNode *head = new ListNode();
        ListNode *it = head;
        ListNode *p = list1, *q = list2;
        while (true) {
            if (!p) {
                it->next = q;
                break;
            }
            if (!q) {
                it->next = p;
                break;
            }
            if (p->val < q->val) {
                it->next = p;
                it = it->next;
                p = p->next;
            }
            else {
                it->next = q;
                it = it->next;
                q = q->next;
            }
        }
        return head->next;
    }
};
#endif //LEETCODE_N21_H
