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
	int sumOfLeftLeaves(TreeNode* root) {
		return solve1(root);
		// return solve2(root);
	}

	// solution 1
	int solve1(TreeNode* root) {
		return solve1dfs(root, false);
	}
	int solve1dfs(TreeNode* root, bool isLeft) {
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
		return solve1dfs(root->left, true) + solve1dfs(root->right, false);
	}

	// solution 2
	int solve2(TreeNode* root) {
		if (!root) {
			return 0;
		}
		int ans = 0;
		if (root->left) {
			if (!root->left->left && !root->left->right) {
				ans += root->left->val;
			} else {
				ans += sumOfLeftLeaves(root->left);
			}
		}
		if (root->right) {
			ans += sumOfLeftLeaves(root->right);
		}
		return ans;
	}
};
