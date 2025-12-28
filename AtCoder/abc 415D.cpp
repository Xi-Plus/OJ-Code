// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	long long n, m;
	cin >> n >> m;
	vector<pair<long long, long long>> v;
	long long a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v.push_back({a - b, a});
	}
	sort(v.begin(), v.end());
	long long ans = 0, used;
	for (int i = 0; i < m; i++) {
		if (n >= v[i].second) {
			used = (n - v[i].second) / v[i].first + 1;
			ans += used;
			n -= used * v[i].first;
		}
	}
	cout << ans << endl;
}
