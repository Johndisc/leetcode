//
// Created by 58253 on 2023/1/12.
//

#ifndef LEETCODE_N124_H
#define LEETCODE_N124_H
#include "global.h"

class Solution {
public:
    int path = INT_MIN;

    int findPath(TreeNode *root) {
        if (!root->left && !root->right) {
            path = max(path, root->val);
            return root->val;
        }
        int left, right;
        if (!root->left) {
            right = max(findPath(root->right), 0);
            path = max(path, right + root->val);
            return right + root->val;
        }
        if (!root->right) {
            left = max(findPath(root->left), 0);
            path = max(path, left + root->val);
            return left + root->val;
        }
        left = findPath(root->left);
        right = findPath(root->right);
        int sidemax = max(left, right);
        sidemax = max(sidemax, 0);
        path = max(path, sidemax + root->val);
        path = max(path, left + right + root->val);
        return sidemax + root->val;
    }
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        findPath(root);
        return path;
    }
};
#endif //LEETCODE_N124_H
