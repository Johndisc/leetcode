//
// Created by 58253 on 2022/9/19.
//

#ifndef LEETCODE_N133_H
#define LEETCODE_N133_H

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
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:

    void constructNode(Node *node, Node *new_node, unordered_map<int, Node *> &table) {
        for (auto item: node->neighbors) {
            if (table.find(item->val) == table.end()) {
                Node *new_neighbor = new Node(item->val);
                table[item->val] = new_neighbor;
                new_node->neighbors.push_back(new_neighbor);
                constructNode(item, new_neighbor, table);
            }
            else
                new_node->neighbors.push_back(table[item->val]);
        }
    }

    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        unordered_map<int, Node *> table;
        Node *new_node = new Node(node->val);
        table[node->val] = new_node;
        constructNode(node, new_node, table);
        return new_node;
    }
};
#endif //LEETCODE_N133_H
