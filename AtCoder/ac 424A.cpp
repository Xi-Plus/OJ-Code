// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	if (a == b || b == c || a == c) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
