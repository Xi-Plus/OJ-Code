// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
long long l[25];

int calc(long long v) {
	int ans = 0;
	long long pos = 1, prevPos = 1;
	for (int i = 0; i < n; i++) {
		prevPos = pos;
		if (v & 1) {
			pos -= l[i];
			if (pos < 1 && prevPos >= 1) {
				ans++;
			}
		} else {
			pos += l[i];
			if (pos >= 1 && prevPos < 1) {
				ans++;
			}
		}
		v >>= 1;
	}
	return ans;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}
	int ans = 0;
	for (long long i = (1LL << n) - 1; i >= 0; i--) {
		ans = max(ans, calc(i));
	}
	cout << ans << endl;
}
