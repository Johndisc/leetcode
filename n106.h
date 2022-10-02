//
// Created by 58253 on 2022/9/19.
//

#ifndef LEETCODE_N106_H
#define LEETCODE_N106_H

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
    TreeNode *buildPart(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe) {
        if (pe == ps)
            return nullptr;
        TreeNode *treeNode = new TreeNode(postorder[pe - 1]);
        if (pe - ps == 1)
            return treeNode;
        int i = is;
        for (; i < ie; i++) {
            if (inorder[i] == postorder[pe - 1]) {
                treeNode->left = buildPart(inorder, is, i, postorder, ps, ps + i - is);
                treeNode->right = buildPart(inorder, i + 1, ie, postorder, ps + i - is, pe - 1);
                break;
            }
        }
        return treeNode;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildPart(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};
#endif //LEETCODE_N106_H
