// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
long long k;
long long a[200005];

bool check(long long target) {
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < target) {
			cnt += (target - a[i] - 1) / (i + 1) + 1;
		}
		if (cnt > k) {
			return false;
		}
	}
	return true;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long l = 1, r = 9e18, m;
	while (l < r) {
		m = (l + r) / 2;
		if (check(m)) {
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	if (check(l)) {
		cout << l << endl;
	} else {
		cout << l - 1 << endl;
	}
}
