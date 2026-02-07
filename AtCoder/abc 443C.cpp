// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, t;
	cin >> n >> t;
	int a;
	int ans = 0, isOpen = true, prevOpen = 0;
	while (n--) {
		cin >> a;
		if (prevOpen < a) {
			ans += a - prevOpen;
			isOpen = false;
			prevOpen = a + 100;
		}
	}
	if (prevOpen < t) {
		ans += t - prevOpen;
	}
	cout << ans << endl;
}
