// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int BIT[500005];
int lowbit(int x) {
	return x & -x;
}
void update(int x) {
	while (x < 500005) {
		BIT[x] += 1;
		x += lowbit(x);
	}
}
int sum(int x) {
	int ans = 0;
	while (x > 0) {
		ans += BIT[x];
		x -= lowbit(x);
	}
	return ans;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ca[n + 1], cb[n + 1];
	ca[0] = 0;
	cb[0] = 0;
	for (int i = 1; i <= n; i++) {
		ca[i] = ca[i - 1] + (s[i - 1] == 'A');
		cb[i] = cb[i - 1] + (s[i - 1] == 'B');
	}
	vector<int> d;
	for (int i = 0; i <= n; i++) {
		d.push_back(ca[i] - cb[i]);
	}
	cout << endl;
	vector<int> ds(d.begin(), d.end());
	sort(ds.begin(), ds.end());
	for (int i = 0; i < d.size(); i++) {
		d[i] = lower_bound(ds.begin(), ds.end(), d[i]) - ds.begin() + 1;
	}
	long long ans = 0;
	for (int i = 0; i < d.size(); i++) {
		ans += sum(d[i] - 1);
		update(d[i]);
	}
	cout << ans << endl;
}
