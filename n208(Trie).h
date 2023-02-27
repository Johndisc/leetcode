//
// Created by 58253 on 2022/10/2.
//

#ifndef LEETCODE_N208_H
#define LEETCODE_N208_H

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

class Trie {
public:
    struct Node {
        bool is_end;
        Node *child[26];
        Node() {
            is_end = false;
            for (int i = 0; i < 26; ++i)
                child[i] = nullptr;
        }
    };

    Node *root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node *node = root;
        for (char &c: word) {
            int index = c - 'a';
            if (!node->child[index])
                node->child[index] = new Node();
            node = node->child[index];
        }
        node->is_end = true;
    }

    bool search(string word) {
        Node *node = root;
        for (char &c: word) {
            int index = c - 'a';
            node = node->child[index];
            if (!node)
                return false;
        }
        if (node->is_end)
            return true;
        else
            return false;
    }

    bool startsWith(string prefix) {
        Node *node = root;
        for (char &c: prefix) {
            int index = c - 'a';
            node = node->child[index];
            if (!node)
                return false;
        }
        return true;
    }
};
#endif //LEETCODE_N208_H
