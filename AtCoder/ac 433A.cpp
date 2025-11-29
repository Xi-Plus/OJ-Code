// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int x, y, z;
	cin >> x >> y >> z;
	if (x - y * z >= 0 && (x - y * z) % (z - 1) == 0) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
