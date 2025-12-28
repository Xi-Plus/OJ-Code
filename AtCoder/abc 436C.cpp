// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	int r, c;
	set<pair<int, int>> s;
	int ans = 0;
	while (m--) {
		cin >> r >> c;
		if (!s.count({r, c}) && !s.count({r, c + 1}) && !s.count({r + 1, c}) && !s.count({r + 1, c + 1})) {
			s.insert({r, c});
			s.insert({r, c + 1});
			s.insert({r + 1, c});
			s.insert({r + 1, c + 1});
			ans++;
		}
	}
	cout << ans << endl;
}
