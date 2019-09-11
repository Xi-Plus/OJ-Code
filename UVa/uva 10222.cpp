#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string t;
	map<char, char> book;
	t="qwertyuiop[]\\";
	for(int q=t.size()-1; q>=2; q--){
		book[t[q]] = t[q-2];
	}
	t="asdfghjkl;'";
	for(int q=t.size()-1; q>=2; q--){
		book[t[q]] = t[q-2];
	}
	t="zxcvbnm,./";
	for(int q=t.size()-1; q>=2; q--){
		book[t[q]] = t[q-2];
	}
	book[' ']=' ';
	string s;
	while(getline(cin, s)){
		for(auto c:s){
			cout<<book[c];
		}
		cout<<endl;
	}
}
