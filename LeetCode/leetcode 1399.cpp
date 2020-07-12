#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
	int countLargestGroup(int n) {
		map<int, int> count;
		int t, sum;
		for (int i = 1; i <= n; i++) {
			t = i;
			sum = 0;
			while (t) {
				sum += t % 10;
				t /= 10;
			}
			count[sum]++;
		}
		int groupcnt = 0, maxcount = 0;
		for (auto v : count) {
			if (v.second == maxcount) {
				groupcnt++;
			} else if (v.second > maxcount) {
				groupcnt = 1;
				maxcount = v.second;
			}
		}
		return groupcnt;
	}
};

int main() {
	printf("%d\n", Solution().countLargestGroup(13));
	printf("%d\n", Solution().countLargestGroup(2));
	printf("%d\n", Solution().countLargestGroup(15));
	printf("%d\n", Solution().countLargestGroup(24));
}
