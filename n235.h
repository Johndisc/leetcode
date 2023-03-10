//
// Created by 58253 on 2023/3/5.
//

#ifndef LEETCODE_N235_H
#define LEETCODE_N235_H
#include "global.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int small = p->val < q->val ? p->val : q->val;
        int big = p->val > q->val ? p->val : q->val;
        if (root->val >= small && root->val <= big)
            return root;
        else if (root->val > big)
            return lowestCommonAncestor(root->left, p, q);
        else
            return lowestCommonAncestor(root->right, p, q);
    }
};
#endif //LEETCODE_N235_H
