#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
	int reverse(int x) {
		string s = to_string(x);
		string n = "";
		if (s[0] == '-') {
			n = "-";
			s = s.substr(1);
		}
		std::reverse(s.begin(), s.end());
		long long ans = stoll(n + s);
		if (ans < -2147483648LL || ans > 2147483647LL) {
			return 0;
		}
		return ans;
	}
};
