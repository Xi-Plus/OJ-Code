#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
bool cmp(pair<char, int> a, pair<char, int> b){
	if(b.second==a.second){
		return a.first<b.first;
	}
	return a.second>b.second;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	cin.ignore();
	string s;
	set<char> chars;
	map<char, int> cnt;
	while(n--){
		getline(cin, s);
		for(char c:s){
			if('a'<=c&&c<='z'){
				cnt[c-32]++;
				chars.insert(c);
			}else if('A'<=c&&c<'Z'){
				cnt[c]++;
				chars.insert(c);
			}
		}
	}
	vector<pair<char, int>> v;
	for(auto c:cnt){
		v.push_back(c);
	}
	sort(v.begin(), v.end(), cmp);
	for(auto c:v){
		cout<<c.first<<" "<<c.second<<endl;
	}
}
