// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m, ans = 0;
	cin >> n >> m;
	while (n && m) {
		m = n % m;
		ans++;
	}
	cout << ans << endl;
}
