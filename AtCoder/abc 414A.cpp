// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, l, r;
	cin >> n >> l >> r;
	int ans = 0;
	int x, y;
	while (n--) {
		cin >> x >> y;
		if (x <= l && y >= r) {
			ans++;
		}
	}
	cout << ans << endl;
}
