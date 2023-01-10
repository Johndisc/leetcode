//
// Created by 58253 on 2023/1/10.
//

#ifndef LEETCODE_N116_H
#define LEETCODE_N116_H
#include "global.h"

class Solution {
public:
    Node* connect(Node* root) {
        Node *node = root, *front;
        while (node && node->left && node->right) {
            front = node;
            while (node) {
                node->left->next = node->right;
                if (node->next)
                    node->right->next = node->next->left;
                node = node->next;
            }
            node = front->left;
        }
        return root;
    }
};
#endif //LEETCODE_N116_H
