//
// Created by CGCL on 2023/2/22.
//

#ifndef LEETCODE_N199_H
#define LEETCODE_N199_H
#include "global.h"

class Solution {
public:
	vector<int> res;
	
	void findRes(TreeNode *node, int level) {
		printf("%d ", node->val);
		if (level >= res.size())
			res.push_back(node->val);
		if (node->right)
			findRes(node->right, level + 1);
		if (node->left)
			findRes(node->left, level + 1);
	}
	
	vector<int> rightSideView(TreeNode* root) {
		if (!root)
			return res;
		findRes(root, 0);
		return res;
	}
};
#endif //LEETCODE_N199_H
