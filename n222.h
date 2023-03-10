//
// Created by 58253 on 2023/3/5.
//

#ifndef LEETCODE_N222_H
#define LEETCODE_N222_H
#include "global.h"

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int num = 1 + countNodes(root->left) + countNodes(root->right);
        return num;
    }
};
#endif //LEETCODE_N222_H
