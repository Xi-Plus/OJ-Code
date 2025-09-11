// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int a, b;
	char c;
	cin >> a >> c >> b;
	if (b == 8) {
		cout << a + 1 << "-" << 1 << endl;
	} else {
		cout << a << "-" << b + 1 << endl;
	}
}
