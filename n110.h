//
// Created by 58253 on 2023/1/9.
//

#ifndef LEETCODE_N110_H
#define LEETCODE_N110_H
#include "global.h"

class Solution {
public:
    pair<bool, int> judge(TreeNode *node, int height) {
        if (!node)
            return make_pair(true, height);
        auto left = judge(node->left, height + 1);
        if (!left.first)
            return make_pair(false, height);
        auto right = judge(node->right, height + 1);
        if (!right.first || abs(left.second - right.second) > 1)
            return make_pair(false, height);
        return make_pair(true, max(left.second, right.second));
    }

    bool isBalanced(TreeNode* root) {
        return judge(root, 0).first;
    }
};
#endif //LEETCODE_N110_H
