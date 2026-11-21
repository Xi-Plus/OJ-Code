// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	char c[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
		}
	}
	bool ans;
	for (int i = 0; i < n; i++) {
		ans = true;
		for (int j = 0; j < m; j++) {
			if (c[i][j] == 'o') {
				ans = false;
			}
		}
		if (ans) {
			cout << "Faucet " << i + 1 << endl;
			return 0;
		}
	}
	for (int i = 0; i < m; i++) {
		ans = true;
		for (int j = 0; j < n; j++) {
			if (c[j][i] == 'o') {
				ans = false;
			}
		}
		if (ans) {
			cout << "Drain " << i + 1 << endl;
			return 0;
		}
	}
}
