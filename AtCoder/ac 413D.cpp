// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		long long a;
		vector<pair<long long, long long>> v(n);
		int cntMinus = 0;
		bool allSame = true;
		for (int q = 0; q < n; q++) {
			cin >> a;
			v[q].first = abs(a);
			v[q].second = a;
			if (a < 0) {
				cntMinus++;
			}
			if (v[q].first != v[0].first) {
				allSame = false;
			}
		}
		sort(v.begin(), v.end());
		bool ans = true;
		if (allSame) {
			if (cntMinus == 0 || cntMinus == n) {
				// ok
			} else {
				if (n % 2 == 0) {
					ans = (cntMinus == n / 2);
				} else {
					ans = (cntMinus == n / 2 || cntMinus == n / 2 + 1);
				}
			}
		} else {
			for (int q = 0; q < n - 2; q++) {
				if (v[q + 1].second * v[q + 1].second != v[q].second * v[q + 2].second) {
					ans = false;
					break;
				}
			}
		}
		if (ans) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}
