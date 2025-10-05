// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	string s;
	unordered_map<char, int> cnt;
	cin >> s;
	for (auto c : s) {
		cnt[c]++;
	}
	for (auto [c, n] : cnt) {
		if (n == 1) {
			cout << c << endl;
		}
	}
}
