// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void sol1(int a, int b, const string& s) {
	int n = s.size();
	int ans = 0;
	for (int r = 0; r < n; r++) {
		int ca = 0, cb = 0, ans2 = 0;
		for (int l = r; l >= 0; l--) {
			if (s[l] == 'a') {
				ca++;
			} else {
				cb++;
			}
			if (ca >= a && cb < b) {
				ans2++;
			}
		}
		cout << "r=" << r << ", ca=" << ca << ", cb=" << cb << ", ans2=" << ans2 << endl;
		ans += ans2;
	}
	cout << ans << endl;
	cout << "----------------" << endl;
}

void sol2(int a, int b, const string& s) {
	int n = s.size();
	// cout << "n=" << n << endl;
	int ca = 0, cb = 0;
	int l = 0, ra = 0, rb = 0;
	int cur;
	long long ans = 0;
	while (l < n) {
		while (cb < b && rb < n) {
			if (s[rb] == 'b') {
				cb++;
			}
			rb++;
		}
		while (ca < a && ra < n) {
			if (s[ra] == 'a') {
				ca++;
			}
			ra++;
		}
		// cout << "l=" << l << ", ra=" << ra << ", rb=" << rb << ", ca=" << ca << ", cb=" << cb << ", ans=" << rb - ra + (cb < b ? 1 : 0) << endl;
		if (ca >= a) {
			ans += max(rb - ra + (cb < b ? 1 : 0), 0);
		}
		if (s[l] == 'a') {
			ca--;
		} else {
			cb--;
		}
		l++;
	}
	cout << ans << endl;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	// sol1(a, b, s);
	sol2(a, b, s);
}
