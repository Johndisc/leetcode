//
// Created by 58253 on 2022/9/19.
//

#ifndef LEETCODE_N105_H
#define LEETCODE_N105_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *buildPart(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie) {
        if (pe == ps)
            return nullptr;
        TreeNode *treeNode = new TreeNode(preorder[ps]);
        if (pe - ps == 1)
            return treeNode;
        int i = is;
        for (; i < ie; i++) {
            if (inorder[i] == preorder[ps]) {
                treeNode->left = buildPart(preorder, ps + 1, ps + 1 + i - is, inorder, is, i);
                treeNode->right = buildPart(preorder, ps + 1 + i - is, pe, inorder, i + 1, ie);
                break;
            }
        }
        return treeNode;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildPart(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
#endif //LEETCODE_N105_H
