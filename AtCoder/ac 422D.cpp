// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[(1LL << 20) + 5];
void dfs(long long l, long long r, long long sum) {
	if (l == r) {
		a[l] = sum;
		return;
	}
	dfs(l, (l + r) / 2, sum / 2);
	dfs((l + r) / 2 + 1, r, (sum + 1) / 2);
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	long long n, k;
	cin >> n >> k;
	long long len = 1 << n;
	dfs(1, len, k);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (k % 2) {
			ans = 1;
		}
		k /= 2;
	}
	cout << ans << endl;
	for (int i = 1; i <= len; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
