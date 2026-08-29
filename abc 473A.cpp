// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int ans = 0;
	int t;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		if (i >= n / 2 + 1) {
			ans += t;
		}
	}
	cout << ans << endl;
}
