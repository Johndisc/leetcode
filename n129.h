//
// Created by 58253 on 2023/1/13.
//

#ifndef LEETCODE_N129_H
#define LEETCODE_N129_H
#include "global.h"

class Solution {
public:
    int total = 0;

    void compute(TreeNode *root, int cur) {
        if (!root->left && !root->right) {
            cur += root->val;
            total += cur;
            return;
        }
        int val = (cur + root->val) * 10;
        if (root->left)
            compute(root->left, val);
        if ((root->right))
            compute(root->right, val);
    }

    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;
        compute(root, 0);
        return total;
    }
};
#endif //LEETCODE_N129_H
