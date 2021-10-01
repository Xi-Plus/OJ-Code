#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k, a, b = -1;
	cin >> n >> k;
	if (k >= n) {
		cout << "YES" << endl;
		return 0;
	}

	for (int i = 0; i < k; i++) {
		cin >> a;
	}
	cin >> b;
	if (a == b) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
	}
}
