// By xiplus
typedef vector<vector<int>> vector2d;
class Solution {
   public:
	int findCircleNum(vector2d& isConnected) {
		return disjointSet(isConnected);
		// return dfs(isConnected);
	}
	int dfs(vector2d& isConnected) {
		int n = isConnected.size();
		vector<int> edges[n];
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (isConnected[i][j] == 1) {
					edges[i].push_back(j);
					edges[j].push_back(i);
				}
			}
		}
		vector<bool> visited(n, false);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				ans++;
				dfsCore(edges, visited, i);
			}
		}
		return ans;
	}
	void dfsCore(vector<int> edges[], vector<bool>& visited, int x) {
		if (visited[x]) {
			return;
		}
		visited[x] = true;
		for (auto y : edges[x]) {
			dfsCore(edges, visited, y);
		}
	}
	int disjointSet(vector2d& isConnected) {
		int n = isConnected.size();
		vector<int> parent(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (isConnected[i][j] == 1) {
					parent[findParent(parent, j)] = findParent(parent, i);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			parent[i] = findParent(parent, i);
			if (parent[i] == i) {
				ans++;
			}
		}
		return ans;
	}
	int findParent(vector<int>& parent, int x) {
		if (parent[x] == x) {
			return x;
		}
		return parent[x] = findParent(parent, parent[x]);
	}
};
