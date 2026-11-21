// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int MAXN = 300005;
int a[MAXN], b[MAXN], c[MAXN];
bool valid(int l, int r) {
	return a[l] < a[r] && b[l] < b[r] && c[l] < c[r];
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		a[i + 1] = a[i] + (s[i] == 'A');
		b[i + 1] = b[i] + (s[i] == 'B');
		c[i + 1] = c[i] + (s[i] == 'C');
	}
	// for (int i = 1; i <= n; i++) {
	// 	cerr << a[i] << " ";
	// }
	// cerr << "\n";
	// for (int i = 1; i <= n; i++) {
	// 	cerr << b[i] << " ";
	// }
	// cerr << "\n";
	// for (int i = 1; i <= n; i++) {
	// 	cerr << c[i] << " ";
	// }
	// cerr << "\n";
	int r1 = 1, r2 = n;
	while (!valid(r2, n) && r2 >= 1) {
		r2--;
	}
	if (r2 < 1) {
		cout << 0 << "\n";
		return 0;
	}

	long long ans = 0;
	for (int l = 1; l <= n; l++) {
		if (!valid(0, l)) {
			continue;
		}
		while (!valid(l, r1) && r1 <= n) {
			r1++;
		}
		if (r1 > r2) {
			break;
		}
		ans += (r2 - r1 + 1);
	}
	cout << ans << endl;
}
