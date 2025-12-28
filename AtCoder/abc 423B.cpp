// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, a, l = -1, r = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 1) {
			if (l == -1) {
				l = i;
			}
			r = i;
		}
	}
	cout << r - l << endl;
}
