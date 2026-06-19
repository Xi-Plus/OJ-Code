// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	for (auto c : s) {
		if ('0' <= c && c <= '9') cout << c;
	}
	cout << endl;
}
