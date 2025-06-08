// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t, n, k;
	string s;
	cin >> t;
	while (t--) {
		cin >> n >> k >> s;
		int cnt1 = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') {
				cnt1++;
			}
		}
		int remain = cnt1 - (n / 2 - k);
		if (remain >= 0 && remain <= k * 2 && remain % 2 == 0) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}

/*
6
6 2
000000
2 1
01
4 1
1011
10 2
1101011001
10 1
1101011001
2 1
11
*/
