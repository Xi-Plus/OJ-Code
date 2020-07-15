#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
	int subarraysDivByK(vector<int>& A, int K) {
		int sum = 0, ans = 0;
		unordered_map<int, int> count;
		count[0] = 1;
		for (int i = 0; i < A.size(); i++) {
			sum += A[i];
			sum = (sum % K + K) % K;
			ans += count[sum];
			count[sum]++;
		}
		return ans;
	}
};

int main() {
	vector<int> arr = {4, 5, 0, -2, -3, 1};
	printf("%d\n", Solution().subarraysDivByK(arr, 5));
}
