//
// Created by 58253 on 2023/1/3.
//

#ifndef LEETCODE_N94_H
#define LEETCODE_N94_H
#include "global.h"

class Solution {
public:
    vector<int> res;

    void findRes(TreeNode* node) {
        if (!node)
            return;
        findRes(node->left);
        res.push_back(node->val);
        findRes(node->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        findRes(root);
        return res;
    }
};
#endif //LEETCODE_N94_H
