// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int pos[35];
int target[35];
int ans = 0;
void dfs(int n, int t) {
	if (n == 0) {
		return;
	}
	if (pos[n] == t) {
		dfs(n - 1, t);
	} else {
		int other = 6 - pos[n] - t;
		dfs(n - 1, other);
		pos[n] = t;
		ans++;
		dfs(n - 1, t);
	}
}
int main() {
	int n;
	while (cin >> n && n) {
		for (int i = 1; i <= n; i++) {
			cin >> pos[i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> target[i];
		}
		ans = 0;
		for (int i = n; i >= 1; i--) {
			if (pos[i] != target[i]) {
				dfs(i - 1, 6 - pos[i] - target[i]);
				pos[i] = target[i];
				ans++;
			}
		}
		cout << ans << endl;
	}
}
