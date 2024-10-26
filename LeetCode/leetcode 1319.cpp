// By xiplus
class Solution {
   public:
	int makeConnected(int n, vector<vector<int>>& connections) {
		if (connections.size() < n - 1) {
			return -1;
		}
		vector<int> parent(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
		for (auto edge : connections) {
			int x = findParent(parent, edge[0]);
			int y = findParent(parent, edge[1]);
			parent[x] = y;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (parent[i] == i) {
				ans++;
			}
		}
		return ans - 1;
	}
	int findParent(vector<int>& parent, int x) {
		if (parent[x] == x) {
			return x;
		}
		return parent[x] = findParent(parent, parent[x]);
	}
};
