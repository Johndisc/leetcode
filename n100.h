//
// Created by 58253 on 2023/1/4.
//

#ifndef LEETCODE_N100_H
#define LEETCODE_N100_H
#include "global.h"

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if ((p && !q) || (q && !p))
            return false;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
#endif //LEETCODE_N100_H
