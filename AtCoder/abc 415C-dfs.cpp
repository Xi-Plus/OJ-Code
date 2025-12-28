// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, target;
bool ans[1 << 18];
bool visited[1 << 18];
string s;
bool dfs(int val) {
	if (val == target) {
		return true;
	}
	if (visited[val]) {
		return ans[val];
	}
	visited[val] = true;
	for (int i = 1; i <= n; i++) {
		int next = val | (1 << (i - 1));
		if (s[next - 1] == '0') {
			if (dfs(next)) {
				return ans[val] = true;
			}
		}
	}
	return ans[val] = false;
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		target = (1 << n) - 1;
		cin >> s;
		fill_n(ans, 1 << n, false);
		fill_n(visited, 1 << n, false);
		ans[0] = true;
		if (dfs(0)) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}
