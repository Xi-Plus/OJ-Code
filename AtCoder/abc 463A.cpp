// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int x, y;
	cin >> x >> y;
	if (x % 16 == 0 && y % 9 == 0 && x / 16 == y / 9) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
