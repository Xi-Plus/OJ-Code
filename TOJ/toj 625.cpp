#include <bits/stdc++.h>
using namespace std;
int main() {
	int t, n, k, v[200005];
	cin >> t;
	while (t--) {
		cin >> n >> k;
		v[1] = 1;
		v[2] = 1;
		for (int i = 3; i <= n; i++) {
			v[i] = v[i - 1] * 2;
			if (i >= k + 2) {
				v[i] -= v[i - k - 1];
			}
			v[i] = (v[i]%10007+10007)%10007;
		}
		cout << v[n] << endl;
	}
}
