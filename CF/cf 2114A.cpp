// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, s;
	cin >> n;
	while (n--) {
		cin >> s;
		int s2 = sqrt(s);
		if (s == s2 * s2) {
			cout << s2 / 2 << " " << s2 - s2 / 2 << endl;
		} else {
			cout << -1 << endl;
		}
	}
}

/*
5
0001
1001
1000
4900
2025
*/
