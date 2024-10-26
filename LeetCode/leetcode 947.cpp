// By xiplus
class Solution {
   public:
	int removeStones(vector<vector<int>>& stones) {
		vector<int> parent(20003, 0);
		int ans = 0;
		for (auto stone : stones) {
			int x = findParent(parent, stone[0] + 1, ans);
			int y = findParent(parent, stone[1] + 10002, ans);
			if (x != y) {
				parent[x] = y;
				ans--;
			}
		}
		return stones.size() - ans;
	}
	int findParent(vector<int>& parent, int x, int& ans) {
		if (parent[x] == 0) {
			parent[x] = x;
			ans++;
		}
		if (parent[x] == x) {
			return x;
		}
		return parent[x] = findParent(parent, parent[x], ans);
	}
};
