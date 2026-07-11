// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void sol() {
	long long x, y, k;
	cin >> x >> y >> k;
	int cnt = 0;
	while (x != y) {
		if (x > y) {
			x /= k;
		} else {
			y /= k;
		}
		cnt++;
	}
	cout << cnt << endl;
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}
