// By xiplus
// WIP
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Edge {
	int from, to;
	bool operator<(const Edge& rhs) const {
		return from > rhs.from;
	}
};

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	int x, y;
	vector<Edge> e;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		if (x < y) {
			e.push_back({x, y});
		}
	}
	sort(e.begin(), e.end());
	cout << e[0].from << " " << e[0].to << endl;
	int dp[n + 1] = {};
	dp[n] = 1;
	int ei = 0;
	for (int i = n - 1; i >= 1; i--) {
		while (ei < e.size() && e[ei].from == i) {
			dp[i] += dp[e[ei].to];
			ei++;
		}
		cout << i << " " << dp[i] << endl;
	}
	cout << dp[1] << endl;
}
