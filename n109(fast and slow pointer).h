//
// Created by 58253 on 2023/1/9.
//

#ifndef LEETCODE_N109_FAST_AND_SLOW_POINTER_H
#define LEETCODE_N109_FAST_AND_SLOW_POINTER_H
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

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        return buildTree(nums, 0, nums.size() - 1);
    }
};
#endif //LEETCODE_N109_FAST_AND_SLOW_POINTER_H
