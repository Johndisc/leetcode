//
// Created by CGCL on 2023/3/8.
//

#ifndef LEETCODE_N226_H
#define LEETCODE_N226_H
#include "global.h"

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if(!root)
			return nullptr;
		if (root->left)
			invertTree(root->left);
		if (root->right)
			invertTree(root->right);
		auto mid = root->left;
		root->left = root->right;
		root->right = mid;
		return root;
	}
};
#endif //LEETCODE_N226_H
