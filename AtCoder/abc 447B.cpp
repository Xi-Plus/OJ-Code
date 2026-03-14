// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	string s;
	int maxn = 0;
	cin >> s;
	unordered_map<char, int> cnt;
	for (auto& c : s) {
		cnt[c]++;
		maxn = max(maxn, cnt[c]);
	}
	char maxch;
	set<char> remove;
	for (auto [c, n] : cnt) {
		if (maxn == n) {
			remove.insert(c);
		}
	}
	for (auto& c : s) {
		if (!remove.count(c)) {
			cout << c;
		}
	}
	cout << endl;
}
