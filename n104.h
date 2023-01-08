//
// Created by 58253 on 2023/1/8.
//

#ifndef LEETCODE_N104_H
#define LEETCODE_N104_H
#include "global.h"

class Solution {
public:
    int findDepth(TreeNode *node, int depth) {
        if (!node->left && !node->right)
            return depth;
        int mdepth = 0;
        if (node->left)
            mdepth = findDepth(node->left, depth + 1);
        if (node->right)
            mdepth = max(mdepth, findDepth(node->right, depth + 1));
        return mdepth;
    }
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        return findDepth(root, 1);
    }
};
#endif //LEETCODE_N104_H
