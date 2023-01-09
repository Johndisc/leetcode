//
// Created by 58253 on 2023/1/9.
//

#ifndef LEETCODE_N114_H
#define LEETCODE_N114_H
#include "global.h"

class Solution {
public:
    TreeNode *flattenSide(TreeNode *root) {
        if (!root->left && !root->right)
            return root;
        TreeNode *left;
        if (root->left) {
            left = flattenSide(root->left);
            left->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        if (root->right)
            return flattenSide(root->right);
        else
            return left;
    }

    void flatten(TreeNode* root) {
        if (!root)
            return;
        flattenSide(root);
    }
};
#endif //LEETCODE_N114_H
