// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int a[n + 1];
	for (int q = 1; q <= n; q++) {
		cin >> a[q];
	}
	sort(a + 1, a + n + 1, greater<int>());
	int ans = 0;
	for (int q = 1; q <= n; q++) {
		if (a[q] >= q) {
			ans = q;
		} else {
			break;
		}
	}
	cout << ans << endl;
}
