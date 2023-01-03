//
// Created by 58253 on 2023/1/3.
//

#ifndef LEETCODE_N95_H
#define LEETCODE_N95_H
#include "global.h"

class Solution {
public:

    vector<TreeNode*> construct(int start, int end) {
        if (start == end)
            return {nullptr};
        vector<TreeNode *> trees;

        TreeNode *node;
        for (int i = start; i < end; ++i) {

            vector<TreeNode *> left = construct(start, i);
            vector<TreeNode *> right = construct(i + 1, end);

            for (auto lt: left) {
                for (auto rt: right) {
                    node = new TreeNode;
                    node->val = i;
                    node->left = lt;
                    node->right = rt;
                    trees.push_back(node);
                }
            }
        }
        return trees;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return {};
        return construct(1, n + 1);
    }
};
#endif //LEETCODE_N95_H
