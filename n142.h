//
// Created by 58253 on 2022/9/20.
//

#ifndef LEETCODE_N142_H
#define LEETCODE_N142_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <map>

using namespace std;

struct ListNode {

    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head)
            return nullptr;
        unordered_set<ListNode*> table;
        table.insert(head);
        while (head->next) {
            if (table.find(head->next) != table.end())
                return head->next;
            table.insert(head->next);
            head = head->next;
        }
        return nullptr;
    }
};
#endif //LEETCODE_N142_H
