//
// Created by 58253 on 2022/8/15.
//

#ifndef LEETCODE_N19_H
#define LEETCODE_N19_H
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *map_to_node[30];
        ListNode *it = head;
        int cnt = 0;
        while (it) {
            map_to_node[cnt] = it;
            it = it->next;
            cnt++;
        }
        if (n == cnt) {
            head = head->next;
        }
        else {
            it = map_to_node[cnt - n - 1];
            it->next = it->next->next;
        }
        return head;
    }
};
#endif //LEETCODE_N19_H
