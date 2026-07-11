// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	bool left = false;
	vector<int> l;
	stack<int> r;
	for (int i = n; i >= 1; i--) {
		if (s[i - 1] == 'o') {
			left = !left;
		}
		if (left) {
			l.push_back(i);
		} else {
			r.push(i);
		}
	}
	for (auto& v : l) {
		cout << v << " ";
	}
	while (!r.empty()) {
		cout << r.top() << " ";
		r.pop();
	}
	cout << endl;
}
