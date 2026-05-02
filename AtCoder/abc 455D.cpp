// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int pre[300005], nxt[300005], head[300005];
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		head[i] = i;
	}
	int c, p;
	while (q--) {
		cin >> c >> p;
		if (pre[c] != 0) {
			nxt[pre[c]] = 0;
		} else {
			head[c] = 0;
		}
		nxt[p] = c;
		pre[c] = p;
	}
	for (int i = 1; i <= n; i++) {
		if (head[i] != 0) {
			int cnt = 0, cur = head[i];
			while (cur != 0) {
				cnt++;
				cur = nxt[cur];
			}
			cout << cnt << ' ';
		} else {
			cout << "0 ";
		}
	}
	cout << endl;
}
