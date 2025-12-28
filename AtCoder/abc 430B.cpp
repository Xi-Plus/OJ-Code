// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	string s[n];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	unordered_set<string> all;
	for (int q = 0; q < n - m + 1; q++) {
		for (int w = 0; w < n - m + 1; w++) {
			string temp = "";
			for (int e = 0; e < m; e++) {
				for (int r = 0; r < m; r++) {
					temp += s[q + e][w + r];
				}
			}
			all.insert(temp);
		}
	}
	cout << all.size() << endl;
}
