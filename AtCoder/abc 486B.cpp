// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	set<int> s;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		s.insert(a);
	}
	int b;
	while (m--) {
		cin >> a >> b;
		s.erase(a);
		s.insert(b);
	}
	for (auto v : s) {
		cout << v << " ";
	}
	cout << endl;
}
