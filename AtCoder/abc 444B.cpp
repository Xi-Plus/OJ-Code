// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int sum(int n) {
	int ans = 0;
	while (n) {
		ans += n % 10;
		n /= 10;
	}
	return ans;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		if (sum(i) == k) {
			ans++;
		}
	}
	cout << ans << endl;
}
