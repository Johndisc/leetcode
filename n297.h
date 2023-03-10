//
// Created by CGCL on 2023/3/6.
//

#ifndef LEETCODE_N297_H
#define LEETCODE_N297_H
#include "global.h"

class Codec {
public:
	
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		if (!root)
			return "null";
		queue<TreeNode *> q;
		string res;
		q.push(root);
		res += to_string(root->val) + ",";
		while (!q.empty()) {
			TreeNode *node = q.front();
			q.pop();
			if (!node->left)
				res += "null,";
			else {
				q.push(node->left);
				res += to_string(node->left->val) + ",";
			}
			if (!node->right)
				res += "null,";
			else {
				q.push(node->right);
				res += to_string(node->right->val) + ",";
			}
		}
		return res;
	}
	
	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data == "null")
			return nullptr;
		TreeNode *root, *node;
		int i = 0, j = 0;
		string s;
		while (j < data.size() && data[j] != ',')
			j++;
		s = data.substr(i, j - i);
		
		root = new TreeNode(stoi(s));
		i = j + 1;
		j = i;
		queue<TreeNode *> q;
		q.push(root);
		while (i != data.size() - 1) {
			node = q.front();
			q.pop();
			while (j < data.size() && data[j] != ',')
				j++;
			s = data.substr(i, j - i);
			if (s == "null")
				node->left = nullptr;
			else {
				TreeNode *child = new TreeNode(stoi(s));
				node->left = child;
				q.push(child);
			}
			i = j + 1;
			j = i;
			
			while (j < data.size() && data[j] != ',')
				j++;
			s = data.substr(i, j - i);
			if (s == "null")
				node->right = nullptr;
			else {
				TreeNode *child = new TreeNode(stoi(s));
				node->right = child;
				q.push(child);
			}
			i = j + 1;
			j = i;
		}
		return root;
	}
};
#endif //LEETCODE_N297_H
