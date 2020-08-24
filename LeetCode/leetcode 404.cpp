#include <bits/stdc++.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   public:
	int answer(TreeNode* root, bool isLeft) {
		if (!root) {
			return 0;
		}
		if (!root->left && !root->right) {
			if (isLeft) {
				return root->val;
			} else {
				return 0;
			}
		}
		return answer(root->left, true) + answer(root->right, false);
	}
	int sumOfLeftLeaves(TreeNode* root) {
		return answer(root, false);
	}
};
