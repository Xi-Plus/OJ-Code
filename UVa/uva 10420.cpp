#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	string s;
	set<string> country;
	map<string, int> cnt;
	while(n--){
		cin>>s;
		country.insert(s);
		cnt[s]++;
		getline(cin, s);
	}
	vector<string> v(country.begin(), country.end());
	sort(v.begin(), v.end());
	for(auto c:v){
		cout<<c<<" "<<cnt[c]<<endl;
	}
}
