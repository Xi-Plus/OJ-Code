#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
	int reverse(int x) {
		long long x2 = x;
		string n = "";
		if (x2 < 0) {
			n = "-";
			x2 = -x2;
		}
		string s = to_string(x2);
		std::reverse(s.begin(), s.end());
		long long ans = stoll(n + s);
		if (ans < -2147483648LL || ans > 2147483647LL) {
			return 0;
		}
		return ans;
	}
};
