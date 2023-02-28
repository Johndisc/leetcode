//
// Created by CGCL on 2023/2/28.
//

#ifndef LEETCODE_N337_H
#define LEETCODE_N337_H
#include "global.h"

class Solution {
public:
	pair<int, int> robOne(TreeNode *root) {
		if (!root->left && !root->right)
			return make_pair(root->val, 0);
		int rb = root->val, nrb = 0;
		pair<int, int> childnum;
		if (root->left) {
			childnum = robOne(root->left);
			rb += childnum.second;
			nrb = max(childnum.first, childnum.second);
		}
		if (root->right) {
			childnum = robOne(root->right);
			rb += childnum.second;
			nrb += max(childnum.first, childnum.second);
		}
		return make_pair(rb, nrb);
	}
	int rob(TreeNode* root) {
		auto num = robOne(root);
		return max(num.first, num.second);
	}
};
#endif //LEETCODE_N337_H
