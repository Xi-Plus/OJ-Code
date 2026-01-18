// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	bool va[255] = {}, vb[255] = {};
	char c;
	while (n--) {
		cin >> c;
		va[c] = true;
	}
	while (m--) {
		cin >> c;
		vb[c] = true;
	}
	int q;
	cin >> q;
	string s;
	while (q--) {
		cin >> s;
		bool a = true, b = true;
		for (auto& c : s) {
			a &= va[c];
			b &= vb[c];
		}
		if (a && !b) {
			cout << "Takahashi" << endl;
		} else if (!a && b) {
			cout << "Aoki" << endl;
		} else {
			cout << "Unknown" << endl;
		}
	}
}
