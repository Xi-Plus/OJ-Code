// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	long long ans1 = 0, ans2 = 0;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'B') {
			ans1 += abs(cnt * 2 + 1 - i);
			ans2 += abs(cnt * 2 - i);
			cnt++;
		}
	}
	cout << min(ans1, ans2) << endl;
}
