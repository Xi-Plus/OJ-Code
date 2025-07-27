// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(n);
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			ans += a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			ans += b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int i = n - 1;
		int j = 0;
		while (j < n) {
			if (a[i] + b[j] >= m) {
				break;
			}
			j++;
		}
		while (i >= 0 && j < n) {
			if (a[i] + b[j] >= m) {
				ans -= m;
				i--;
				j++;
			} else {
				j++;
			}
		}
		cout << ans << endl;
	}
}
