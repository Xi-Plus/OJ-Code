// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	string s;
	cin >> n;
	cin.ignore();
	while (n--) {
		getline(cin, s);
		unordered_map<char, int> cnt;
		int maxn = 0;
		for (auto &c : s) {
			c = tolower(c);
			if ('a' <= c && c <= 'z') {
				cnt[c]++;
				maxn = max(maxn, cnt[c]);
			}
		}
		for (char c = 'a'; c <= 'z'; c++) {
			if (cnt[c] == maxn) {
				cout << c;
			}
		}
		cout << endl;
	}
}
/*
1
Computers account for only 5% of the country’s commercial electricity consumption.
*/
