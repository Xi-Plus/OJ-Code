// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	int n[s.size()];
	n[0] = 0;
	for (int i = 0; i < s.size(); i++) {
		n[i + 1] = n[i] + (s[i] == 't');
	}
	double ans = 0;
	for (int l = 0; l < s.size(); l++) {
		for (int r = l + 2; r < s.size(); r++) {
			if (s[l] == 't' && s[r] == 't') {
				ans = max(ans, (double)(n[r + 1] - n[l] - 2) / (r - l - 1));
			}
		}
	}
	cout << fixed << setprecision(20) << ans << endl;
}
