// By xiplus
// subtask 1, 19 points
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Node {
	int pos;
	int type;
	int val;
	bool operator<(const Node& rhs) const {
		if (pos != rhs.pos) {
			return pos < rhs.pos;
		}
		return val > rhs.val;
	}
};

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int m, n;
	cin >> m >> n;
	vector<Node> a;
	int l, r;
	stack<int> s;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		a.push_back({(l - 1) * 2 + 1, 0, l});
		a.push_back({r * 2, 1, l});
	}
	sort(a.begin(), a.end());
	for (auto [pos, type, val] : a) {
		if (type == 0) {
			s.push(val);
		} else {
			if (s.empty()) {
				cout << n - 1 << endl;
				return 0;
			}
			if (s.top() != val) {
				cout << n - 1 << endl;
				return 0;
			}
			s.pop();
		}
	}
	cout << n << endl;
}
