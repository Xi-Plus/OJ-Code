// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int f(int x) {
	int ans = 0;
	while (x) {
		ans += (x % 10) * (x % 10);
		x /= 10;
	}
	return ans;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	while (n >= 10) {
		n = f(n);
	}
	if (n == 1) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
