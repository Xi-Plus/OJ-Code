// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int a = 0, b = 0, c = 0, t, d;
	while (n--) {
		cin >> t;
		d = t / 1000;
		if (t % 1000) {
			d++;
		}
		d *= 1000;
		a += (d - t) / 100;
		b += (d - t) % 100 / 10;
		c += (d - t) % 10;
	}
	cout << c << " " << b << " " << a << endl;
}
