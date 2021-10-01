#include <bits/stdc++.h>
using namespace std;
int main() {
	int a[2];
	cin >> a[0] >> a[1];

	int gcd = __gcd(a[0], a[1]);
	a[0] /= gcd;
	a[1] /= gcd;

	stack<pair<int, int>> s;

	while (a[0] && a[1]) {
		if (a[0] >= a[1]) {
			s.push({0, a[0] / a[1]});
			a[0] %= a[1];
		} else {
			s.push({1, a[1] / a[0]});
			a[1] %= a[0];
		}
	}
	int x[2] = {};
	if (a[0]) {
		x[0] = 1;
	} else {
		x[1] = 1;
	}
	while (!s.empty()) {
		x[1 - s.top().first] -= x[s.top().first] * s.top().second;
		s.pop();
	}
	cout << x[0] << " " << x[1] << endl;
}
