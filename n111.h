//
// Created by 58253 on 2023/1/9.
//

#ifndef LEETCODE_N111_H
#define LEETCODE_N111_H
#include "global.h"

class Solution {
public:
    int getMin(TreeNode *node, int depth) {
        if (!node)
            return depth;
        if (!node->left)
            return getMin(node->right, depth + 1);
        else if (!node->right)
            return getMin(node->left, depth + 1);
        else
            return min(getMin(node->left, depth + 1), getMin(node->right, depth + 1));
    }

    int minDepth(TreeNode* root) {
        return getMin(root, 0);
    }
};
#endif //LEETCODE_N111_H
