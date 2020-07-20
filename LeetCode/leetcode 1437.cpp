#include <bits/stdc++.h>
class Solution {
   public:
	string destCity(vector<vector<string>>& paths) {
		unordered_map<string, int> count;
		for (auto&& path : paths) {
			count[path[0]]++;
			count[path[1]]--;
		}
		for (auto&& v : count) {
			if (v.second == -1) {
				return v.first;
			}
		}
		return "";
	}
};
