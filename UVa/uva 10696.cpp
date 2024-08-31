// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long f91(long long n) {
	if (n <= 100) {
		return f91(f91(n + 11));
	} else {
		return n - 10;
	}
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n, n) {
		cout << "f91(" << n << ") = " << f91(n) << endl;
	}
}
/*
500
91
0
*/
