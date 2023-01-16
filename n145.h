//
// Created by 58253 on 2023/1/14.
//

#ifndef LEETCODE_N145_H
#define LEETCODE_N145_H
#include "global.h"

class Solution {
public:
    vector<int> res;

    void traverse(TreeNode *root) {
        if (!root)
            return;
        traverse(root->left);
        traverse(root->right);
        res.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        traverse(root);
        return res;
    }
};
#endif //LEETCODE_N145_H
