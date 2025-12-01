// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	int cnt[m + 1] = {};
	double total[m + 1] = {};
	int a, b;
	while (n--) {
		cin >> a >> b;
		cnt[a]++;
		total[a] += b;
	}
	cout << fixed << setprecision(10);
	for (int i = 1; i <= m; i++) {
		cout << total[i] / cnt[i] << endl;
	}
}
