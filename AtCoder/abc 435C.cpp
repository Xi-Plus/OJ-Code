// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 1, cur = 1;
	while (cur <= ans && cur <= n) {
		ans = max(ans, cur + a[cur] - 1);
		cur++;
	}
	cout << min(ans, n) << endl;
}
