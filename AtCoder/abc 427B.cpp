// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	n--;
	long long a = 1, b;
	while (n--) {
		b = a;
		while (b) {
			a += b % 10;
			b /= 10;
		}
	}
	cout << a << endl;
}
