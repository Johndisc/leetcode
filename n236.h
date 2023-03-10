//
// Created by CGCL on 2023/3/3.
//

#ifndef LEETCODE_N236_H
#define LEETCODE_N236_H
#include "global.h"

class Solution {
public:
	pair<int, TreeNode *> findAncestor(TreeNode *node, TreeNode *p, TreeNode *q) {
		pair<int, TreeNode *> left(0, nullptr), right(0, nullptr);
		if (node->left) {
			left = findAncestor(node->left, p, q);
			if (left.first == 3)
				return left;
		}
		if (node->right) {
			right = findAncestor(node->right, p, q);
			if (right.first == 3)
				return right;
		}
		if ((left.first + right.first == 3) || (left.first + right.first == 1 && node == q) || (left.first + right.first == 2 && node == p))
			return make_pair(3, node);
		else if (left.first + right.first == 1 || node == p)
			return make_pair(1, p);
		else if (left.first + right.first == 2 || node == q)
			return make_pair(2, q);
		else
			return make_pair(0, nullptr);
	}
	
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		auto item = findAncestor(root, p, q);
		return item.second;
	}
};

		2
		  1
#endif //LEETCODE_N236_H
