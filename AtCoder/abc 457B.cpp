// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> a(n);
	int l;
	for (int i = 0; i < n; i++) {
		cin >> l;
		a[i].resize(l);
		for (auto& v : a[i]) {
			cin >> v;
		}
	}
	int x, y;
	cin >> x >> y;
	cout << a[x - 1][y - 1] << endl;
}
