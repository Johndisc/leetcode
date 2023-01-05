//
// Created by 58253 on 2023/1/5.
//

#ifndef LEETCODE_N101_H
#define LEETCODE_N101_H
#include "global.h"

class Solution {
public:
    bool check(TreeNode *left, TreeNode *right) {
        if (!left && !right)
            return true;
        if ((!left && right) || (left && !right))
            return false;
        if (left->val != right->val)
            return false;
        return check(left->left, right->right) && check(left->right, right->left);

    }

    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return check(root->left, root->right);
    }
};
#endif //LEETCODE_N101_H
