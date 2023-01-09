//
// Created by 58253 on 2023/1/9.
//

#ifndef LEETCODE_N113_H
#define LEETCODE_N113_H
#include "global.h"

class Solution {
public:
    vector<vector<int>> res;

    void findPath(TreeNode *root, int targetSum, vector<int> &path) {
        if (!root->left && !root->right) {
            if (targetSum == root->val) {
                path.push_back(root->val);
                res.push_back(path);
                path.pop_back();
            }
            return;
        }
        path.push_back(root->val);

        if (root->left)
            findPath(root->left, targetSum - root->val, path);

        if (root->right)
            findPath(root->right, targetSum - root->val, path);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        if (!root)
            return res;
        findPath(root, targetSum, path);
        return res;
    }
};
#endif //LEETCODE_N113_H
