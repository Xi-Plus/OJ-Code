// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, a, b, ans = 0;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		if (b > a) {
			ans++;
		}
	}
	cout << ans << endl;
}
