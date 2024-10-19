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
	int getMinimumDifference(TreeNode* root) {
		int prevVal = -1;
		int ans = 2e9;
		dfs(root, prevVal, ans);
		return ans;
	}
	void dfs(TreeNode* root, int& prevVal, int& ans) {
		if (!root) {
			return;
		}
		dfs(root->left, prevVal, ans);
		if (prevVal != -1) {
			ans = min(ans, abs(root->val - prevVal));
		}
		prevVal = root->val;
		dfs(root->right, prevVal, ans);
	}
};
