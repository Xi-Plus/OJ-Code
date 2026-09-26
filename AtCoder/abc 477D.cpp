// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Input {
	int type;
	int x;
	char c;
};
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<Input> in(q);
	vector<bool> mask(n, false);
	set<int> s;
	for (int i = 0; i < q; i++) {
		cin >> in[i].type;
		if (in[i].type == 1) {
			cin >> in[i].x;
			in[i].x--;
			mask[in[i].x] = !mask[in[i].x];
		} else {
			cin >> in[i].c;
		}
	}
	for (int i = 0; i < n; i++) {
		if (!mask[i]) {
			s.insert(i);
		}
	}
	string ans(n, '?');
	for (int i = q - 1; i >= 0; i--) {
		if (in[i].type == 1) {
			if (mask[in[i].x]) {
				mask[in[i].x] = false;
				if (ans[in[i].x] == '?') {
					s.insert(in[i].x);
				}
			} else {
				mask[in[i].x] = true;
				auto it = s.find(in[i].x);
				if (it != s.end()) {
					s.erase(it);
				}
			}
		} else {
			for (auto v : s) {
				ans[v] = in[i].c;
			}
			s.clear();
		}
	}
	for (int i = 0; i < n; i++) {
		if (ans[i] == '?') {
			ans[i] = 'a';
		}
	}
	cout << ans << endl;
}
