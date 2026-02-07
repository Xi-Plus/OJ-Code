// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<int> v;
vector<int> idx;
vector<int> fixCnt;

void sol() {
	int n;
	cin >> n;
	v.resize(n);
	idx.resize(n);
	fixCnt.resize(n);
	fill_n(fixCnt.begin(), n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		idx[i] = i;
	}
	sort(idx.begin(), idx.end(), [&](int a, int b) {
		return v[a] < v[b];
	});
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		// cout << i << " " << idx[i] << " " << v[i] << endl;
		if (fixCnt[idx[i]] > 0) {
			continue;
		}
		for (int j = idx[i] + 1; j < n; j++) {
			if (fixCnt[j] >= 2) {
				break;
			}
			if (v[j] < v[j - 1]) {
				break;
			}
			if (v[j] > v[j - 1] + 1) {
				ans += v[j] - v[j - 1] - 1;
				// cout << "fix " << j << " from " << v[j] << " to " << v[j - 1] + 1 << endl;
				v[j] = v[j - 1] + 1;
			}
			fixCnt[j]++;
		}
		for (int j = idx[i] - 1; j >= 0; j--) {
			if (fixCnt[j] >= 2) {
				break;
			}
			if (v[j] < v[j + 1]) {
				break;
			}
			if (v[j] > v[j + 1] + 1) {
				ans += v[j] - v[j + 1] - 1;
				// cout << "fix " << j << " from " << v[j] << " to " << v[j + 1] + 1 << endl;
				v[j] = v[j + 1] + 1;
			}
			fixCnt[j]++;
		}
	}
	// for (int i = 0; i < n; i++) {
	// 	cout << v[i] << " ";
	// }
	// cout << endl;
	cout << ans << endl;
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}
