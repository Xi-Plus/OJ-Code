// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long
int lowbit(int x) {
	return x & (-x);
}
int bitR[300005], bitC[300005];
void updateR(int x, int v) {
	while (x < 300005) {
		bitR[x] += v;
		x += lowbit(x);
	}
}
int queryR(int x) {
	int sum = 0;
	while (x) {
		sum += bitR[x];
		x -= lowbit(x);
	}
	return sum;
}
void updateC(int x, int v) {
	while (x < 300005) {
		bitC[x] += v;
		x += lowbit(x);
	}
}
int queryC(int x) {
	int sum = 0;
	while (x) {
		sum += bitC[x];
		x -= lowbit(x);
	}
	return sum;
}

int rowPrev[300005] = {};
bool rowPaint[300005] = {};
int colPrev[300005] = {};
signed main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	int t, v;
	long long ans = 0;
	for (int i = 1; i <= q; i++) {
		cin >> t >> v;
		if (t == 1) {
			if (!rowPaint[v]) {
				ans += n;
				rowPaint[v] = true;
			} else {
				ans += queryR(i) - queryR(rowPrev[v]);
			}
			if (rowPrev[v]) {
				updateC(rowPrev[v], -1);
			}
			updateC(i, 1);
			rowPrev[v] = i;
		} else {
			ans -= queryC(i) - queryC(colPrev[v]);
			if (colPrev[v]) {
				updateR(colPrev[v], -1);
			}
			updateR(i, 1);
			colPrev[v] = i;
		}
		cout << ans << endl;
	}
}
