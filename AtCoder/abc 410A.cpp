// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int a[n], k;
	for (int q = 0; q < n; q++) {
		cin >> a[q];
	}
	cin >> k;
	int ans = 0;
	for (int q = 0; q < n; q++) {
		if (a[q] >= k) {
			ans++;
		}
	}
	cout << ans << endl;
}
