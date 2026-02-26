// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<string> s(n);
	int len = 0;
	for (auto& a : s) {
		cin >> a;
		len = max(len, (int)a.size());
	}
	for (auto& a : s) {
		for (int i = 0; i < (len - a.size()) / 2; i++) {
			cout << '.';
		}
		cout << a;
		for (int i = 0; i < (len - a.size()) / 2; i++) {
			cout << '.';
		}
		cout << endl;
	}
}
