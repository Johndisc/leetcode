//
// Created by 58253 on 2022/9/19.
//

#ifndef LEETCODE_N141_H
#define LEETCODE_N141_H

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
    bool hasCycle(ListNode *head) {
        if (!head)
            return false;
        unordered_set<ListNode*> table;
        table.insert(head);
        while (head->next) {
            if (table.find(head->next) != table.end())
                return true;
            table.insert(head->next);
            head = head->next;
        }
        return false;
    }
};
#endif //LEETCODE_N141_H
