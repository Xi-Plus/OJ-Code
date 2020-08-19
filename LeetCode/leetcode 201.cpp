#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

class Solution {
   public:
	long long lowbit(long long x) {
		return x & (-x);
	}
	int rangeBitwiseAnd(int m, int n) {
		long long temp = (long long)m ^ (long long)n;
		while (temp - lowbit(temp) != 0) {
			temp -= lowbit(temp);
		}
		if (temp > 0) {
			temp = temp * 2 - 1;
		}
		return m & n & (~temp);
	}
};

int main() {
	//	ios::sync_with_stdio(false);
	//	cin.tie(0);
	cout << Solution().rangeBitwiseAnd(5, 7) << endl;
	cout << Solution().rangeBitwiseAnd(0, 1) << endl;
}
