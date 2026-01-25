// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int q;
	cin >> q;
	int t;
	bool play = false;
	int vol = 0;
	while (q--) {
		cin >> t;
		if (t == 1) {
			vol++;
		} else if (t == 2) {
			if (vol > 0) {
				vol--;
			}
		} else {
			play = !play;
		}
		if (play && vol >= 3) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}
