#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s1, s2;
	while(getline(cin, s1)){
		getline(cin, s2);
		map<char, int> cnt1;
		map<char, int> cnt2;
		for(char c:s1) {
			cnt1[c]++;
		}
		for(char c:s2) {
			cnt2[c]++;
		}
		vector<char> v;
		for(auto c:cnt1){
			for(int q=min(c.second, cnt2[c.first]); q>0; q--){
				v.push_back(c.first);
			}
		}
		sort(v.begin(), v.end());
		for(char c:v){
			cout<<c;
		}
		cout<<endl;
	}
}
