//
// Created by 58253 on 2023/1/9.
//

#ifndef LEETCODE_N112_H
#define LEETCODE_N112_H
#include "global.h"

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        if (!root->left && !root->right) {
            if (targetSum == root->val)
                return true;
            else
                return false;
        }
        if (root->left && hasPathSum(root->left, targetSum - root->val))
            return true;
        if (root->right && hasPathSum(root->right, targetSum - root->val))
            return true;
        return false;
    }
};
#endif //LEETCODE_N112_H
