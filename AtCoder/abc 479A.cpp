// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int a, ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (i & 1) {
			ans += a;
		}
	}
	cout << ans << endl;
}
