// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	int v[n];
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		if (v[i] < k && v[i + 1] > k) {
			ans++;
		} else if (v[i] > k && v[i + 1] < k) {
			ans++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (v[i] == k) {
			ans++;
		}
	}
	cout << ans << endl;
}
