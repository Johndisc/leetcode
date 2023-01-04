//
// Created by 58253 on 2023/1/4.
//

#ifndef LEETCODE_N98_H
#define LEETCODE_N98_H
#include "global.h"

class Solution {
public:
    bool valid(TreeNode *node, long long low, long long high) {
        if (node->left) {
            if (node->left->val <= low || node->left->val >= node->val)
                return false;
            if (!valid(node->left, low, node->val))
                return false;
        }
        if (node->right) {
            if (node->right->val >= high || node->right->val <= node->val)
                return false;
            if (!valid(node->right, node->val, high))
                return false;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        long long low = INT_MIN, high = INT_MAX;
        low--;
        high++;
        return valid(root, low, high);
    }
};
#endif //LEETCODE_N98_H
