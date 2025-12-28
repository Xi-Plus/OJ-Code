// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
unordered_map<char, int> dr = {{'U', -1}, {'D', 1}, {'L', 0}, {'R', 0}};
unordered_map<char, int> dc = {{'U', 0}, {'D', 0}, {'L', -1}, {'R', 1}};
unordered_map<char, int> dirn = {{'U', 0}, {'D', 0}, {'L', 1}, {'R', 1}};
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	long long r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	long long n;
	int m, l;
	cin >> n >> m >> l;
	vector<pair<char, int>> act1(m), act2(l);
	for (int i = 0; i < m; i++) {
		cin >> act1[i].first >> act1[i].second;
	}
	for (int i = 0; i < l; i++) {
		cin >> act2[i].first >> act2[i].second;
	}
	int idx1 = 0, idx2 = 0;
	long long ans = 0;
	long long cnt;
	while (idx1 < m && idx2 < l) {
		cnt = min(act1[idx1].second, act2[idx2].second);
		bool found = false;
		if (r1 == r2 && c1 == c2 && act1[idx1].first == act2[idx2].first) {
			ans += cnt;
			found = true;
		}
		if (act1[idx1].first == 'U' && act2[idx2].first == 'D' && c1 == c2 && r1 > r2 && r1 - r2 <= cnt * 2) {
			cnt = (r1 - r2 + 1) / 2;
		} else if (act1[idx1].first == 'D' && act2[idx2].first == 'U' && c1 == c2 && r1 < r2 && r2 - r1 <= cnt * 2) {
			cnt = (r2 - r1 + 1) / 2;
		} else if (act1[idx1].first == 'L' && act2[idx2].first == 'R' && r1 == r2 && c1 > c2 && c1 - c2 <= cnt * 2) {
			cnt = (c1 - c2 + 1) / 2;
		} else if (act1[idx1].first == 'R' && act2[idx2].first == 'L' && r1 == r2 && c1 < c2 && c2 - c1 <= cnt * 2) {
			cnt = (c2 - c1 + 1) / 2;
		} else if (dirn[act1[idx1].first] != dirn[act2[idx2].first] && abs(r1 - r2) == abs(c1 - c2) && abs(r1 - r2) > 0 && abs(r1 - r2) < cnt) {
			cnt = abs(r1 - r2);
		}
		r1 += dr[act1[idx1].first] * cnt;
		c1 += dc[act1[idx1].first] * cnt;
		r2 += dr[act2[idx2].first] * cnt;
		c2 += dc[act2[idx2].first] * cnt;
		if (!found && r1 == r2 && c1 == c2) {
			ans++;
		}
		act1[idx1].second -= cnt;
		act2[idx2].second -= cnt;
		if (act1[idx1].second == 0) {
			idx1++;
		}
		if (act2[idx2].second == 0) {
			idx2++;
		}
	}
	cout << ans << endl;
}
