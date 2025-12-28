// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 200005;
int n, q;
int G[MAXN];

int dpGo[MAXN][32];
int go(int pow, int x) {
	if (dpGo[x][pow] > 0) {
		return dpGo[x][pow];
	}
	if (pow == 0) {
		return dpGo[x][pow] = G[x];
	}
	dpGo[x][pow] = go(pow - 1, go(pow - 1, x));
	return dpGo[x][pow];
}
long long dpSum[MAXN][32];
long long sum(int pow, int x) {
	if (dpSum[x][pow] > 0) {
		return dpSum[x][pow];
	}
	if (pow == 0) {
		return dpSum[x][pow] = x;
	}
	dpSum[x][pow] = sum(pow - 1, x) + sum(pow - 1, go(pow - 1, x));
	return dpSum[x][pow];
}
long long calc(int step, int start) {
	long long ans = 0;
	int low, loglow;
	int tryStepLog = 0, tryStep;
	while (step) {
		tryStep = (1 << tryStepLog);
		if (tryStep & step) {
			ans += sum(tryStepLog, start);
			start = go(tryStepLog, start);
			step -= tryStep;
		}
		tryStepLog++;
	}
	return ans;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	int t;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		G[i] = t;
	}
	int b;
	while (q--) {
		cin >> t >> b;
		cout << calc(t, b) << endl;
	}
}
