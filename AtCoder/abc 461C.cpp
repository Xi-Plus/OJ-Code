// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Node {
	int color;
	long long value;
};
bool cmp(Node a, Node b) {
	return a.value < b.value;
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, k, m;
	cin >> n >> k >> m;
	vector<Node> v(n);
	long long ans = 0;
	vector<int> colorCnt(n + 1);
	int usedColor = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i].color >> v[i].value;
		ans += v[i].value;
		if (colorCnt[v[i].color] == 0) {
			usedColor++;
		}
		colorCnt[v[i].color]++;
	}
	sort(v.begin(), v.end(), cmp);
	int picked = n;
	for (int i = 0; i < n; i++) {
		if (picked == k) {
			break;
		}
		if (usedColor == m && colorCnt[v[i].color] == 1) {
			continue;
		}
		ans -= v[i].value;
		colorCnt[v[i].color]--;
		if (colorCnt[v[i].color] == 0) {
			usedColor--;
		}
		picked--;
	}
	cout << ans << endl;
}
