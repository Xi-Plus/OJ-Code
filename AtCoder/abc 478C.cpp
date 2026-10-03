// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	int l = -1, r = -1;
	for (int i = 0; i < n; i++) {
		if (a[i].second != i) {
			if (l == -1) {
				l = i;
			}
			r = i;
		}
	}
	if (l == -1 || r - l + 1 <= k) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
