#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

/**
 * For ans1
 * 1 = Stan, 2 = Ollie
 *
 * For ans2
 * Ollie, if val < testcase
 * Stan, if val == testcase
 */
int dp[1000005];

void ans1() {
	string outputs[] = {"", "Stan wins", "Ollie wins"};
	const int STAN_WINS = 1;
	const int OLLIE_WINS = 2;
	int n, m, s;
	int choices[15];
	while (cin >> n >> m) {
		memset(dp, 0, sizeof(n));
		for (int i = 0; i < m; i++) {
			cin >> choices[i];
		}
		dp[0] = OLLIE_WINS;
		for (int i = 1; i <= n; i++) {
			dp[i] = OLLIE_WINS;	 // Assume
			for (int j = 0; j < m; j++) {
				s = i - choices[j];
				if (s >= 0 && dp[s] == OLLIE_WINS) {
					dp[i] = STAN_WINS;
					break;
				}
			}
		}
		cout << outputs[dp[n]] << endl;
	}
}

void ans2() {
	int testcase = 0, n, m, s;
	int choices[15];
	while (cin >> n >> m) {
		testcase++;
		for (int i = 0; i < m; i++) {
			cin >> choices[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				s = i - choices[j];
				if (s >= 0 && dp[s] < testcase) {
					dp[i] = testcase;
					break;
				}
			}
		}
		if (dp[n] == testcase) {
			cout << "Stan wins" << endl;
		} else {
			cout << "Ollie wins" << endl;
		}
	}
}
int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	ans1();
}
