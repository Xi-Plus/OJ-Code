// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> h(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	sort(h.begin(), h.end());
	sort(b.begin(), b.end());
	int hi = 0, bi = 0, ans = 0;
	while (hi < n && bi < m) {
		while (h[hi] > b[bi] && bi < m) {
			bi++;
		}
		if (bi >= m) {
			break;
		}
		ans++;
		hi++;
		bi++;
	}
	if (ans >= k) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
