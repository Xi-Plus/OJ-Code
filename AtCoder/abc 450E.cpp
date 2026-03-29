// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long fib[100];
long long cnt[128][100];
long long psum[128][20005];
int maxi;

long long getans(long long i, char c) {
	// cout << "query: " << i << " " << c << endl;
	if (i <= fib[3]) {
		// cout << "ans: " << psum[c][i] << endl;
		return psum[c][i];
	} else {
		int lb = lower_bound(fib, fib + maxi + 1, i + 1) - fib;
		// cout << "ib: " << lb << " " << cnt[c][lb - 1] << " remain: " << i - fib[lb - 1] << endl;
		return cnt[c][lb - 1] + getans(i - fib[lb - 1], c);
	}
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	string x, y;
	cin >> x >> y;
	string sa = x, sb = y, sc;
	// cout << 1 << " " << sa.size() << " " << sa << endl;
	// cout << 2 << " " << sb.size() << " " << sb << endl;
	// for (int i = 0; i < 10; i++) {
	// 	sc = sb + sa;
	// 	cout << i + 3 << " " << sc.size() << " " << sc << endl;
	// 	sa = sb;
	// 	sb = sc;
	// }
	for (char c : x) {
		cnt[c][1]++;
	}
	for (char c : y) {
		cnt[c][2]++;
	}
	string yx = y + x;
	for (int i = 0; i < yx.size(); i++) {
		for (char c = 'a'; c <= 'z'; c++) {
			psum[c][i + 1] = psum[c][i];
		}
		psum[yx[i]][i + 1]++;
	}
	fib[0] = 0;
	fib[1] = x.size();
	fib[2] = y.size();
	for (int i = 3; i <= 92; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		if (fib[i] > 2e18) {
			maxi = i;
			break;
		}
	}
	for (int i = 3; i <= maxi; i++) {
		for (char c = 'a'; c <= 'z'; c++) {
			cnt[c][i] = cnt[c][i - 1] + cnt[c][i - 2];
		}
	}
	// for (int i = 3; i <= 10; i++) {
	// 	cout << "cnt " << i << " " << cnt['c'][i] << endl;
	// }
	// cout << "maxi: " << maxi << endl;
	int q;
	cin >> q;
	long long l, r;
	char c;
	while (q--) {
		cin >> l >> r >> c;
		cout << getans(r, c) - getans(l - 1, c) << endl;
	}
}
