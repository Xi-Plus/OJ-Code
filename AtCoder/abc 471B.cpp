// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	map<string, int> cnt;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
			return std::tolower(c);
		});
		cnt[s]++;
	}
	int maxn = 0;
	for (auto [_, c] : cnt) {
		maxn = max(maxn, c);
	}
	cout << maxn << endl;
}
