// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int h, w, q;
	cin >> h >> w >> q;
	int t, n;
	while (q--) {
		cin >> t >> n;
		if (t == 1) {
			cout << n * w << endl;
			h -= n;
		} else {
			cout << n * h << endl;
			w -= n;
		}
	}
}
