// By xiplus
class Solution {
   public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		vector<int> parent(edges.size() + 1);
		for (int i = 1; i <= edges.size(); i++) {
			parent[i] = i;
		}
		for (auto edge : edges) {
			int x = findParent(parent, edge[0]);
			int y = findParent(parent, edge[1]);
			if (x == y) {
				return edge;
			}
			parent[x] = y;
		}
		return {};
	}
	int findParent(vector<int>& parent, int x) {
		if (parent[x] == x) {
			return x;
		}
		return parent[x] = findParent(parent, parent[x]);
	}
};
