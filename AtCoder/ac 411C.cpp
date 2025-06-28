// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	set<int> s;
	int a;
	while (q--) {
		cin >> a;
		if (s.find(a) == s.end()) {
			s.insert(a);
		} else {
			s.erase(a);
		}
		if (s.find(a + 1) == s.end()) {
			s.insert(a + 1);
		} else {
			s.erase(a + 1);
		}
		cout << s.size() / 2 << endl;
	}
}
