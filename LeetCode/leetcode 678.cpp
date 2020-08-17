#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

/*
"" => 0
"*" => 1
"**" => 2
"*("  => 1, 0
"*(*" => 1, 1
"*(**" => 1, 2
"*(*(" => 1, 1, 0
*/
class Solution {
   public:
	bool checkValidString(string s) {
		vector<int> cnt;
		int idx = 0;
		cnt.push_back(0);

		for (int q = 0; q < s.size(); q++) {
			if (s[q] == '(') {
				// 新增一個項目
				idx++;
				cnt.push_back(0);
			} else if (s[q] == ')') {
				if (idx == 0) {
					// 沒有剩餘的 (
					if (cnt[0] == 0) {
						// 沒有剩餘的 *
						return false;
					} else {
						//消耗剩餘的 *
						cnt[0]--;
					}
				} else {
					// 移除最右邊的 ( ，合併最後兩項
					cnt[idx - 1] += cnt[idx];
					cnt.pop_back();
					idx--;
				}
			} else {  // *
				cnt[idx]++;
			}
		}

		while (idx > 0) {
			if (cnt[idx] == 0) {
				// ( 右邊沒有 * 可供配對
				return false;
			}
			// 消耗一個 * 來移除一個 (
			cnt[idx - 1] += cnt[idx] - 1;
			cnt.pop_back();
			idx--;
		}
		return true;
	}
};

int main() {
	//	ios::sync_with_stdio(false);
	//	cin.tie(0);
	cout << Solution().checkValidString("()") << endl;
	cout << Solution().checkValidString("(*)") << endl;
	cout << Solution().checkValidString("(*))") << endl;
}
