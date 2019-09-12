#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
bool cmp(pair<char, int>a, pair<char, int>b){
	if(a.second==b.second){
		return a.first>b.first;
	}
	return a.second<b.second;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	bool first=false;
	while(getline(cin, s)){
		if(first){
			cout<<endl;
		}
		first=true;
		map<char, int> cnt;
		for(int q=0; q<s.size(); q++){
			cnt[s[q]]++;
		}
		vector<pair<char, int>> v(cnt.begin(), cnt.end());
		sort(v.begin(), v.end(), cmp);
		for(auto c:v){
			cout<<(int)c.first<<" "<<c.second<<endl;
		}
	}
}
