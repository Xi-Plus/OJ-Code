// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		if (i <= m) {
			cout << "OK" << endl;
		} else {
			cout << "Too Many Requests" << endl;
		}
	}
}
