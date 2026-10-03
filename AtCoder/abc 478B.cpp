// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, v;
	cin >> n >> v;
	int w[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	int ans = 0, temp;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				if (i + j + k <= v) {
					temp = w[i] + w[j] + w[k];
					ans = max(ans, temp);
				}
			}
		}
	}
	cout << ans << endl;
}
