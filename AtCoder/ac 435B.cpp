// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int l = 0; l < n; l++) {
		int sum = 0;
		for (int r = l; r < n; r++) {
			sum += a[r];
			bool div = true;
			for (int i = l; i <= r; i++) {
				if (sum % a[i] == 0) {
					div = false;
					break;
				}
			}
			if (div) {
				ans++;
			}
		}
	}
	cout << ans << endl;
}
