// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	int a;
	set<int> s;
	for (int i = 0; i < n; i++) {
		cin >> a;
		s.insert(a % k);
	}
	int ans = *s.rbegin() - *s.begin(), ans2, t;
	for (int i = 0; i < n; i++) {
		t = *s.rbegin();
		s.erase(t);
		s.insert(t - k);
		ans = min(ans, *s.rbegin() - *s.begin());
	}
	cout << ans << endl;
}
