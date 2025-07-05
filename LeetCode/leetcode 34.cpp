// By xiplus
class Solution {
   public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ans;
		auto idx1 = lower_bound(nums.begin(), nums.end(), target);
		if (idx1 != nums.end() && *idx1 == target) {
			ans.push_back(idx1 - nums.begin());
			int idx2 = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
			ans.push_back(idx2);
		} else {
			ans.push_back(-1);
			ans.push_back(-1);
		}
		return ans;
	}
};
