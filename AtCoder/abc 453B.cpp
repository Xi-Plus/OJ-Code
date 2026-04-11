// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t, x;
	cin >> t >> x;
	int saveV;
	cin >> saveV;
	cout << 0 << " " << saveV << endl;
	int v;
	for (int i = 1; i <= t; i++) {
		cin >> v;
		if (abs(v - saveV) >= x) {
			saveV = v;
			cout << i << " " << saveV << endl;
		}
	}
}
