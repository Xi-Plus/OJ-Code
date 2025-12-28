// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	unordered_map<int, int> cnt;
	int a, b;
	while (k--) {
		cin >> a >> b;
		cnt[a]++;
		if (cnt[a] == m) {
			cout << a << " ";
		}
	}
	cout << endl;
}
