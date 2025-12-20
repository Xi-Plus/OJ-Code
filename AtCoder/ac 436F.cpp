// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n;
int tree[500005] = {};
int lowbit(int x) {
	return x & -x;
}
int query(int x) {
	int ans = 0;
	while (x > 0) {
		ans += tree[x];
		x -= lowbit(x);
	}
	return ans;
}
void update(int x) {
	while (x <= n) {
		tree[x] += 1;
		x += lowbit(x);
	}
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	int pos[n + 1], x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		pos[x] = i;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		update(pos[i]);
		long long rank = query(pos[i]);
		ans += rank * (i - rank + 1);
	}
	cout << ans << endl;
}
