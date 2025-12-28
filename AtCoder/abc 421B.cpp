// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	long long x, y;
	cin >> x >> y;
	for (int i = 1; i <= 8; i++) {
		string s = to_string(x + y);
		reverse(s.begin(), s.end());
		long long z = stoll(s);
		x = y;
		y = z;
	}
	cout << y << endl;
}
