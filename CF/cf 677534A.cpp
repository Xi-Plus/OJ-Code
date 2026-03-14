// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int calc(int x) {
	int ans = 0, t;
	while (x) {
		t = x % 10;
		ans += t * t;
		x /= 10;
	}
	return ans;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int x;
	cin >> x;
	int ans = 0;
	unordered_set<int> s;
	s.insert(x);
	while (true) {
		if (x == 1) {
			cout << ans << endl;
			break;
		}
		x = calc(x);
		ans++;
		if (s.count(x)) {
			cout << x << endl;
			break;
		}
		s.insert(x);
	}
}
