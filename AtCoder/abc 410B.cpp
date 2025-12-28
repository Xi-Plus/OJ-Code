// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	int x;
	int cnt[n + 1] = {};
	for (int i = 0; i < q; i++) {
		cin >> x;
		if (x > 0) {
			cnt[x]++;
			cout << x << " ";
		} else {
			int mincnt = 1e9;
			int minidx;
			for (int j = 1; j <= n; j++) {
				if (cnt[j] < mincnt) {
					mincnt = cnt[j];
					minidx = j;
				}
			}
			cnt[minidx]++;
			cout << minidx << " ";
		}
	}
	cout << endl;
}
