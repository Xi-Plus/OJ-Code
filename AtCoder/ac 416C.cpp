// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, k, x;
	cin >> n >> k >> x;
	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	vector<string> s2;
	int dig[k + 1] = {};
	while (dig[k] == 0) {
		string t;
		for (int i = 0; i < k; i++) {
			t += s[dig[i]];
		}
		s2.push_back(t);
		dig[0]++;
		for (int i = 0; i < k; i++) {
			if (dig[i] == n) {
				dig[i] = 0;
				dig[i + 1]++;
			} else {
				break;
			}
		}
	}
	sort(s2.begin(), s2.end());
	cout << s2[x - 1] << endl;
}
