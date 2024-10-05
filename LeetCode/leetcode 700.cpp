// By xiplus
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
	TreeNode* searchBST(TreeNode* root, int val) {
		return solve1(root, val);
		// return solve2(root, val);
	}

	TreeNode* solve1(TreeNode* root, int val) {
		if (!root) {
			return nullptr;
		}
		if (val == root->val) {
			return root;
		} else if (val > root->val) {
			return solve1(root->right, val);
		} else {
			return solve1(root->left, val);
		}
	}

	TreeNode* solve2(TreeNode* root, int val) {
		while (root) {
			if (val == root->val) {
				return root;
			} else if (val > root->val) {
				root = root->right;
			} else {
				root = root->left;
			}
		}
		return nullptr;
	}
};
