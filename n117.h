//
// Created by 58253 on 2023/1/10.
//

#ifndef LEETCODE_N117_H
#define LEETCODE_N117_H
#include "global.h"

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return root;
        Node *node = root, *front, *last;
        while (node) {
            if (!node->left && !node->right) {
                node = node->next;
                continue;
            }
            front = nullptr;
            last = new Node;
            while (node) {
                if (node->left && !node->right) {
                    last->next = node->left;
                    last = node->left;
                }
                else if (node->right && !node->left) {
                    last->next = node->right;
                    last = node->right;
                }
                else if (node->left && node->right) {
                    last->next = node->left;
                    node->left->next = node->right;
                    last = node->right;
                }
                if (!front)
                    front = node->left ? node->left : node->right;
                node = node->next;
            }
            node = front;
        }
        return root;
    }
};
#endif //LEETCODE_N117_H
