// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
bool used[20];
string s;
long long pow2[20] = {1};
unordered_set<long long> s1, s2;
void dfs(int cur, long long val) {
	if (cur == n / 2) {
		s1.insert(val);
		cout << "insert " << cur << " " << val << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			long long next = val | pow2[i - 1];
			// cout << cur << " " << val << " next " << next << " " << s[next - 1] << endl;
			if (s[next - 1] == '0') {
				used[i] = true;
				dfs(cur + 1, next);
				used[i] = false;
			}
		}
	}
}
bool used2[20];
void dfs2(int cur, long long val) {
	if (cur == n / 2) {
		s2.insert(val);
		cout << "insert2 " << cur << " " << val << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!used2[i]) {
			long long next = val ^ pow2[i - 1];
			cout << cur << " " << val << " next " << next << " " << s[next - 1] << endl;
			if (s[next - 1] == '0') {
				used2[i] = true;
				dfs2(cur - 1, next);
				used2[i] = false;
			}
		}
	}
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	for (int i = 1; i < 20; i++) {
		pow2[i] = pow2[i - 1] * 2;
	}
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> s;
		if (s[pow2[n] - 2] == '1') {
			cout << "No" << endl;
			continue;
		}
		if (n == 1 && s[0] == '0') {
			cout << "Yes" << endl;
			continue;
		}
		s1.clear();
		s2.clear();
		dfs(0, 0);
		// cout << "---" << endl;
		dfs2(n, pow2[n] - 1);
		bool found = false;
		for (auto &v : s1) {
			if (s2.find(v) != s2.end()) {
				found = true;
				break;
			}
		}
		if (found) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}
