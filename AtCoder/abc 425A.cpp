// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += (long long)i * i * i * (i % 2 ? -1 : 1);
	}
	cout << ans << endl;
}
