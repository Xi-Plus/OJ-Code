// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	int e = 0, w = 0;
	for (auto c : s) {
		if (c == 'E') {
			e++;
		} else {
			w++;
		}
	}
	if (e > w) {
		cout << "East" << endl;
	} else {
		cout << "West" << endl;
	}
}
