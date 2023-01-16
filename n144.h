//
// Created by 58253 on 2023/1/14.
//

#ifndef LEETCODE_N144_H
#define LEETCODE_N144_H
#include "global.h"

class Solution {
public:
    vector<int> res;

    void traverse(TreeNode *root) {
        if (!root)
            return;
        res.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        traverse(root);
        return res;
    }
};
#endif //LEETCODE_N144_H
