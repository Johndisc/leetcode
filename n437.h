//
// Created by CGCL on 2023/3/3.
//

#ifndef LEETCODE_N437_H
#define LEETCODE_N437_H
#include "global.h"

class Solution {
public:
	int path(TreeNode* root, int targetSum, bool started) {
		if (!root)
			return 0;
		int total = 0;
		if (!started)
			total += path(root->left, targetSum, false) + path(root->right, targetSum, false);
		if (root->val == targetSum)
			total += 1;
		
		if ((root->val > 0 && targetSum >= INT_MIN + root->val) || root->val <= 0 && targetSum <= INT_MAX + root->val)
			total += path(root->left, targetSum - root->val, true) + path(root->right, targetSum - root->val, true);
		
		return total;
	}
	
	int pathSum(TreeNode* root, int targetSum) {
		return path(root, targetSum, false);
	}
};
#endif //LEETCODE_N437_H
