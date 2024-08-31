// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n) {
		int v[n];
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		int ans = 0;
		for (int i = n - 2; i >= 0; i--) {
			for (int j = 0; j <= i; j++) {
				if (v[j] > v[j + 1]) {
					swap(v[j], v[j + 1]);
					ans++;
				}
			}
		}
		cout << "Minimum exchange operations : " << ans << endl;
	}
}
/*
3
1 2 3
3
2 3 1
*/
