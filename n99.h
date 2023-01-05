//
// Created by 58253 on 2023/1/5.
//

#ifndef LEETCODE_N99_H
#define LEETCODE_N99_H
#include "global.h"

class Solution {
public:
    void midTraverse(vector<int> &traversal, TreeNode *node) {
        if (!node)
            return;
        midTraverse(traversal, node->left);
        traversal.push_back(node->val);
        midTraverse(traversal, node->right);
    }

    void recover(int m1, int m2, TreeNode *node) {
        if (!node)
            return;
        if (node->val == m1)
            node->val = m2;
        else if (node->val == m2)
            node->val = m1;
        recover(m1, m2, node->left);
        recover(m1, m2, node->right);
    }

    void recoverTree(TreeNode* root) {
        vector<int> traversal;
        int m1, m2 = -1, i = 0;
        midTraverse(traversal, root);
        for (; i < traversal.size() - 1; ++i) {
            if (traversal[i] > traversal[i + 1]) {
                m1 = i;
                i += 2;
                break;
            }
        }
        printf("%d\n", i);
        for (; i < traversal.size(); ++i) {
            if (traversal[i] < traversal[i - 1]) {
                m2 = i;
                break;
            }
        }
        if (m2 == -1)
            m2 = m1 + 1;
        printf("%d\n", i);
        printf("%d %d\n", m1, m2);
        recover(traversal[m1], traversal[m2], root);
    }
};
#endif //LEETCODE_N99_H
