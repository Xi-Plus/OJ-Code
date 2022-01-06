// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long v[51] = {1, 1};
	for (int i = 2; i <= 50; i++) {
		v[i] = v[i - 1] + v[i - 2];
	}
	int n;
	while (cin >> n, n) {
		cout << v[n] << endl;
	}
}
