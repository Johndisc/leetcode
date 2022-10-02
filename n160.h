//
// Created by 58253 on 2022/9/24.
//

#ifndef LEETCODE_N160_H
#define LEETCODE_N160_H

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

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> table;
        while (headA) {
            table.insert(headA);
            headA = headA->next;
        }
        while (headB) {
            if (table.count(headB))
                return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};
#endif //LEETCODE_N160_H
