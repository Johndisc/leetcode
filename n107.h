//
// Created by 58253 on 2023/1/9.
//

#ifndef LEETCODE_N107_H
#define LEETCODE_N107_H
#include "global.h"

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        TreeNode *node;
        vector<vector<int>> vres;
        deque<vector<int>> res;
        vector<int> mid;
        if (!root)
            return vres;
        queue<pair<TreeNode *, int>> queue;
        queue.push(make_pair(root, 0));
        int level = 0;

        while (!queue.empty()) {
            auto top = queue.front();
            queue.pop();
            if (top.second != level) {
                res.push_front(mid);
                mid.clear();
            }
            node = top.first;
            level = top.second;
            mid.push_back(node->val);
            if (node->left)
                queue.push(make_pair(node->left, level + 1));
            if (node->right)
                queue.push(make_pair(node->right, level + 1));
        }
        res.push_front(mid);
        vres.assign(res.begin(), res.end());
        return vres;
    }
};
#endif //LEETCODE_N107_H
