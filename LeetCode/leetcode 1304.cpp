#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

class Solution {
   public:
	vector<int> sumZero(int n) {
		vector<int> ans;
		if (n & 1) {
			ans.push_back(0);
		}
		for (int q = 1; q <= n / 2; q++) {
			ans.push_back(q);
			ans.push_back(-q);
		}
		return ans;
	}
};

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	for (auto t : Solution().sumZero(5)) {
		cout << t << " ";
	}
	cout << endl;
	for (auto t : Solution().sumZero(3)) {
		cout << t << " ";
	}
	cout << endl;
	for (auto t : Solution().sumZero(1)) {
		cout << t << " ";
	}
	cout << endl;
}
