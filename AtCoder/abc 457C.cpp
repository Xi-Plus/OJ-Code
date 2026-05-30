// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	long long k;
	cin >> n >> k;
	vector<vector<int>> a(n);
	int l;
	for (int i = 0; i < n; i++) {
		cin >> l;
		a[i].resize(l);
		for (auto& v : a[i]) {
			cin >> v;
		}
	}
	int c;
	for (int i = 0; i < n; i++) {
		cin >> c;
		if (k <= (long long)a[i].size() * c) {
			cout << a[i][(k - 1) % a[i].size()] << endl;
			return 0;
		}
		k -= (long long)a[i].size() * c;
	}
}
