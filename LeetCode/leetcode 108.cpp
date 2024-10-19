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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		int size = nums.size();
		return dfs(nums, 0, size - 1);
	}
	TreeNode* dfs(vector<int>& nums, int l, int r) {
		if (l > r) {
			return nullptr;
		}
		int mid = (l + r) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = dfs(nums, l, mid - 1);
		root->right = dfs(nums, mid + 1, r);
		return root;
	}
};
