//
// Created by 58253 on 2023/1/8.
//

#ifndef LEETCODE_N103_H
#define LEETCODE_N103_H
#include "global.h"

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        TreeNode *node;
        vector<vector<int>> res;
        vector<int> vmid;
        deque<int> mid;
        if (!root)
            return res;
        queue<pair<TreeNode *, int>> queue;
        queue.push(make_pair(root, 0));
        int level = 0;

        while (!queue.empty()) {
            auto top = queue.front();
            queue.pop();
            if (top.second != level) {
                vmid.assign(mid.begin(), mid.end());
                res.push_back(vmid);
                mid.clear();
                vmid.clear();
            }
            node = top.first;
            level = top.second;
            if (level % 2)
                mid.push_front(node->val);
            else
                mid.push_back(node->val);
            if (node->left)
                queue.push(make_pair(node->left, level + 1));
            if (node->right)
                queue.push(make_pair(node->right, level + 1));
        }
        vmid.assign(mid.begin(), mid.end());
        res.push_back(vmid);
        return res;
    }
};
#endif //LEETCODE_N103_H
