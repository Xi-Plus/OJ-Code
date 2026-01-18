// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, k;
	long long x;
	cin >> n >> k >> x;
	long long a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, greater<int>());
	long long sum = 0;
	for (int i = n - k; i < n; i++) {
		sum += a[i];
		if (sum >= x) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}
