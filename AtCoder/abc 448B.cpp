// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> c(m);
	for (auto& v : c) {
		cin >> v;
	}
	int a, b, ans = 0, used;
	while (n--) {
		cin >> a >> b;
		used = min(c[a - 1], b);
		ans += used;
		c[a - 1] -= used;
	}
	cout << ans << endl;
}
