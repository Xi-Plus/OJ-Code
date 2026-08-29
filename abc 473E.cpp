// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	int a;
	int sum = 0;
	int foundid = 1;
	unordered_map<int, int> found;
	found[0] = foundid;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		sum = (sum + a) % k;
		if (found[sum] == foundid) {
			ans++;
			foundid++;
			found[sum] = foundid;
		} else {
			found[sum] = foundid;
		}
	}
	cout << ans << endl;
}
