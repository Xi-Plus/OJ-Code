// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	int m;
	cin >> m;
	vector<string> s(m);
	for (int i = 0; i < m; i++) {
		cin >> s[i];
	}
	bool has[n][255] = {};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[j].size() == a[i]) {
				has[i][s[j][b[i] - 1]] = true;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		if (s[i].size() != n) {
			cout << "No" << endl;
			continue;
		}
		bool ok = true;
		for (int j = 0; j < n; j++) {
			if (!has[j][s[i][j]]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}
