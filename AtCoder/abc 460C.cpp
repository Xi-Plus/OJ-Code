// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (auto& v : a) {
		cin >> v;
	}
	for (auto& v : b) {
		cin >> v;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int i = 0, j = 0, ans = 0;
	while (i < n && j < m) {
		if (b[j] <= a[i] * 2) {
			ans++;
			i++;
			j++;
		} else {
			i++;
		}
	}
	cout << ans << endl;
}
