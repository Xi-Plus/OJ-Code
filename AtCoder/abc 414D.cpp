// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<long long> pos(n);
	for (int i = 0; i < n; i++) {
		cin >> pos[i];
	}
	sort(pos.begin(), pos.end());
	long long ans = pos[n - 1] - pos[0];
	vector<long long> dis;
	for (int i = 0; i < n - 1; i++) {
		dis.push_back(pos[i + 1] - pos[i]);
	}
	sort(dis.begin(), dis.end());
	for (int i = n - 2; i >= n - m; i--) {
		ans -= dis[i];
	}
	cout << ans << endl;
}
