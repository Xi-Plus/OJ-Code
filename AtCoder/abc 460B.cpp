// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	long long x1, y1, r1, x2, y2, r2;
	while (t--) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		long long t = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		if ((r1 - r2) * (r1 - r2) <= t && t <= (r1 + r2) * (r1 + r2)) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}
