#include <bits/stdc++.h>
using namespace std;
int main() {
	int t, n, k, ans;
	cin >> t;
	while (t--) {
		cin >> n;
		ans = 0;
		while (n--) {
			cin >> k;
			ans += k;
		}
		cout << ans << endl;
	}
}
