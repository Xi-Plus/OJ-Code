// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	map<int, vector<int>> cnt3, cnt5, cnt7;
	int n;
	cin >> n;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a % 3 == 0) {
			cnt3[a / 3].push_back(i);
		}
		if (a % 5 == 0) {
			cnt5[a / 5].push_back(i);
		}
		if (a % 7 == 0) {
			cnt7[a / 7].push_back(i);
		}
	}
	long long ans = 0;
	for (auto& [ratio, _] : cnt3) {
		if (cnt5.count(ratio) && cnt7.count(ratio)) {
			sort(cnt3[ratio].begin(), cnt3[ratio].end());
			sort(cnt5[ratio].begin(), cnt5[ratio].end());
			sort(cnt7[ratio].begin(), cnt7[ratio].end());
			// cout << ratio << " ";
			// cout << " 3:";
			// for (auto v : cnt3[ratio]) {
			// 	cout << " " << v;
			// }
			// cout << " 5:";
			// for (auto v : cnt5[ratio]) {
			// 	cout << " " << v;
			// }
			// cout << " 7:";
			// for (auto v : cnt7[ratio]) {
			// 	cout << " " << v;
			// }
			// cout << endl;
			long long idx3 = 0, idx7 = 0;
			int sz = cnt5[ratio].size();
			for (int idx5 = 0; idx5 < sz; idx5++) {
				while (cnt3[ratio][idx3] <= cnt5[ratio][idx5] && idx3 < cnt3[ratio].size()) {
					idx3++;
				}
				while (cnt7[ratio][idx7] <= cnt5[ratio][idx5] && idx7 < cnt7[ratio].size()) {
					idx7++;
				}
				ans += idx3 * idx7;
				ans += (cnt3[ratio].size() - idx3) * (cnt7[ratio].size() - idx7);
			}
			cout << endl;
		}
	}
	cout << ans << endl;
}
