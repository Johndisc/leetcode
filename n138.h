//
// Created by 58253 on 2022/9/19.
//

#ifndef LEETCODE_N138_H
#define LEETCODE_N138_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;
        Node *new_head = new Node(head->val);
        Node *p = head->next, *q = new_head;
        unordered_map<Node *, Node *> nmap;
        nmap[head] = new_head;
        while (p) {
            Node *np = new Node(p->val);
            q->next = np;
            q = np;
            nmap[p] = q;
            p = p->next;
        }
        p = head;
        q = new_head;
        while (p) {
            q->random = nmap[p->random];
            p = p->next;
            q = q->next;
        }
        return new_head;
    }
};
#endif //LEETCODE_N138_H
