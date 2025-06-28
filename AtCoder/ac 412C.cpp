// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	int data[200005];
	while (t--) {
		int n;
		cin >> n;
		assert(n >= 2 && n <= 200000);
		for (int i = 0; i < n; i++) {
			cin >> data[i];
			assert(data[i] >= 1 && data[i] <= 1000000000);
		}
		if (n > 3) {
			sort(data + 1, data + n - 1);
		}

		int ans = 1;
		int cur = 0;
		while (true) {
			if (data[cur] * 2 >= data[n - 1]) {
				ans++;
				break;
			}
			auto idx = upper_bound(data + cur + 1, data + n, data[cur] * 2) - data - 1;
			if (data[idx] > data[cur] * 2 || idx == cur) {
				ans = -1;
				break;
			}
			ans++;
			cur = idx;
			if (cur >= n - 1) {
				break;
			}
		}
		cout << ans << endl;
	}
}
