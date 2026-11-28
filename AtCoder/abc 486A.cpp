// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (auto c : s) {
		if (c == 'A') {
			cout << "Alpha ";
		} else if (c == 'B') {
			cout << "Bravo ";
		} else {
			cout << "Charlie ";
		}
	}
	cout << endl;
}
