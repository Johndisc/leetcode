//
// Created by 58253 on 2023/1/9.
//

#ifndef LEETCODE_N108_H
#define LEETCODE_N108_H
#include "global.h"

class Solution {
public:
    TreeNode *buildTree(vector<int> &nums, int s, int e) {
        if (s > e)
            return nullptr;
        int mid = (s + e) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = buildTree(nums, s, mid - 1);
        node->right = buildTree(nums, mid + 1, e);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }
};
#endif //LEETCODE_N108_H
