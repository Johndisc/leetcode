//
// Created by CGCL on 2023/2/12.
//

#ifndef LEETCODE_N173_H
#define LEETCODE_N173_H
#include "global.h"

class BSTIterator {
public:
    stack<TreeNode *> stack;
    BSTIterator(TreeNode* root) {
        while (root) {
            stack.push(root);
            root = root->left;
        }
    }

    int next() {
        TreeNode *node = stack.top();
        int res = node->val;
        stack.pop();
        node = node->right;
        while (node) {
            stack.push(node);
            node = node->left;
        }
        return res;
    }

    bool hasNext() {
        return !stack.empty();
    }
};
#endif //LEETCODE_N173_H
