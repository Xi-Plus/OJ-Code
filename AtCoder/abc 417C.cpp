// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	unordered_map<int, long long> b, c;
	int x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		b[x + i]++;
		c[-(x - i)]++;
	}
	long long ans = 0;
	for (auto it : b) {
		ans += it.second * c[it.first];
	}
	cout << ans << endl;
}
