// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct HashFunc {
	auto operator()(const pair<int, int> &p) const -> size_t {
		return p.first * 3001 + p.second;
	}
};

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, h, m;
	cin >> n >> h >> m;
	int turn = 1;
	// unordered_set<pair<int, int>, HashFunc> s1, s2;
	vector<pair<int, int>> s1, s2;
	s1.push_back(make_pair(h, m));
	int ans = 0;
	int a, b;
	while (n--) {
		// cout << "#" << ans << endl;
		cin >> a >> b;
		bool added = false;
		if (turn == 1) {
			s2.clear();
			for (auto &t : s1) {
				if (t.first >= a) {
					// cout << t.first - a << " " << t.second << endl;
					// s2.insert(make_pair(t.first - a, t.second));
					s2.push_back(make_pair(t.first - a, t.second));
					added = true;
				}
				if (t.second >= b) {
					// cout << t.first << " " << t.second - b << endl;
					// s2.insert(make_pair(t.first, t.second - b));
					s2.push_back(make_pair(t.first, t.second - b));
					added = true;
				}
			}
			turn = 2;
		} else {
			s1.clear();
			for (auto &t : s2) {
				if (t.first >= a) {
					// cout << t.first << " " << t.second - b << endl;
					// s1.insert(make_pair(t.first - a, t.second));
					s1.push_back(make_pair(t.first - a, t.second));
					added = true;
				}
				if (t.second >= b) {
					// cout << t.first << " " << t.second - b << endl;
					// s1.insert(make_pair(t.first, t.second - b));
					s1.push_back(make_pair(t.first, t.second - b));
					added = true;
				}
			}
			turn = 1;
		}
		if (!added) {
			break;
		}
		ans++;
	}
	cout << ans << endl;
}
