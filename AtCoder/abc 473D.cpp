// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, k;
int a[15] = {};
void dfs(int dig, int cur) {
	if (dig == n) {
		if ((k - cur) % dig == 0) {
			for (int i = 1; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << (k - cur) / dig << endl;
		}
	} else {
		for (int i = 0;; i++) {
			a[dig] = i;
			if (cur > k) {
				return;
			}
			dfs(dig + 1, cur);
			cur += dig;
		}
	}
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	dfs(1, 0);
}
