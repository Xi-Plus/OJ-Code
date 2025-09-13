// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	long long t, a, b, c;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		cout << min(a, min(c, (a + b + c) / 3)) << endl;
	}
}
