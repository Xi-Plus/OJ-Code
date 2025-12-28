// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m, a;
	cin >> n >> m;
	unordered_set<int> s;
	while (n--) {
		cin >> a;
		s.insert(a);
		m -= a;
	}
	if (s.count(-m)) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
