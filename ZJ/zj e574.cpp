#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int dp[1000005];  // 0 = Ollie, 1 = Stan

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	string outputs[] = {"Ollie wins", "Stan wins"};
	int n, m, s;
	int choices[15];
	while (cin >> n >> m) {
		memset(dp, 0, sizeof(int) * (n + 5));
		for (int i = 0; i < m; i++) {
			cin >> choices[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				s = i - choices[j];
				if (s >= 0 && dp[s] == 0) {
					dp[i] = 1;
					break;
				}
			}
		}
		cout << outputs[dp[n]] << endl;
	}
}
