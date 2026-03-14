// By xiplus
// TLE
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long x[60005], y[60005];
int n;
long long dis(int a, int b) {
	return abs(x[a] - x[b]) + abs(y[a] - y[b]);
}
const long long v1e10 = 1e10;
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	vector<int> ans(n);
	iota(ans.begin(), ans.end(), 0);
	shuffle(ans.begin(), ans.end(), mt19937(time(NULL)));
	long long total = 0;
	for (int i = 0; i < n; i++) {
		total += dis(ans[i], ans[(i + 1) % n]);
	}
	mt19937 rng(time(NULL));
	int a, b;
	long long change = 0;
	while (total >= v1e10) {
		a = rng() % n;
		b = (a + rng() % (n - 1)) % n;
		// cout << "swap " << a << " " << b << " " << ans[a] << " " << ans[b] << endl;
		change = dis(ans[a], ans[(a + n - 1) % n]);
		change -= dis(ans[a], ans[(a + 1) % n]);
		change -= dis(ans[b], ans[(b + n - 1) % n]);
		change -= dis(ans[b], ans[(b + 1) % n]);
		// cout << dis(ans[a], ans[(a + n - 1) % n]) << " " << dis(ans[a], ans[(a + 1) % n]) << " " << dis(ans[b], ans[(b + n - 1) % n]) << " " << dis(ans[b], ans[(b + 1) % n]) << endl;
		swap(ans[a], ans[b]);
		change += dis(ans[a], ans[(a + n - 1) % n]);
		change += dis(ans[a], ans[(a + 1) % n]);
		change += dis(ans[b], ans[(b + n - 1) % n]);
		change += dis(ans[b], ans[(b + 1) % n]);
		if (change < 0) {
			total += change;
			cout << "do the change " << change << endl;
		} else {
			swap(ans[a], ans[b]);
			// cout << "cancel the change " << change << endl;
		}
		// cout << dis(ans[a], ans[(a + n - 1) % n]) << " " << dis(ans[a], ans[(a + 1) % n]) << " " << dis(ans[b], ans[(b + n - 1) % n]) << " " << dis(ans[b], ans[(b + 1) % n]) << endl;
		cout<<"total: "<<total<<endl;
	}
	assert(total <= v1e10);
	int start = 0;
	while (ans[start] != 0) {
		start++;
	}
	for (int i = 0; i < n; i++) {
		cout << ans[(start + i) % n] + 1 << " ";
	}
	cout << endl;
}
