// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (auto& v : a) {
		cin >> v;
	}
	vector<int> idx(n);
	iota(idx.begin(), idx.end(), 0);
	sort(idx.begin(), idx.end(), [&](int l, int r) {
		return a[l] < a[r];
	});
	int k, b;
	while (q--) {
		cin >> k;
		set<int> s;
		for (int i = 0; i < k; i++) {
			cin >> b;
			s.insert(b - 1);
		}
		for (int i = 0; i < n; i++) {
			if (!s.count(idx[i])) {
				cout << a[idx[i]] << endl;
				break;
			}
		}
	}
}
