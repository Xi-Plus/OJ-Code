// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int s, a, b, x;
	cin >> s >> a >> b >> x;
	cout << x / (a + b) * a * s + min(x % (a + b), a) * s << endl;
}
