// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int p[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	long long ans = 0;
	bool visited[n + 1] = {};
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			int cur = i;
			long long len = 0;
			while (!visited[cur]) {
				visited[cur] = true;
				cur = p[cur];
				len++;
			}
			ans += len * (len - 1) / 2;
		}
	}
	cout << ans << endl;
}
