// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, a, b;
	string s;
	cin >> n >> a >> b >> s;
	for (int i = a; i < n - b; i++) {
		cout << s[i];
	}
	cout << endl;
}
