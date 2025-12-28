// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int d, f;
	cin >> d >> f;
	cout << (f - d % 7 + 6) % 7 + 1 << endl;
}
