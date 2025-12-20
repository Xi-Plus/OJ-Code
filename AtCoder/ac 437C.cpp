// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Node {
	int w, p, sum;
	bool operator<(const Node& rhs) const {
		return sum > rhs.sum;
	}
};

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<Node> v(n);
		long long sumW = 0, sumP = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i].w >> v[i].p;
			v[i].sum = v[i].p + v[i].w;
			sumW += v[i].w;
		}
		sort(v.begin(), v.end());
		int cnt = 0;
		while (sumW > sumP) {
			sumW -= v[cnt].w;
			sumP += v[cnt].p;
			cnt++;
		}
		cout << n - cnt << endl;
	}
}
