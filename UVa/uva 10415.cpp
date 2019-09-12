#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	map<char, string>p;
	p[' ']="0000000000";
	p['c']="0111001111";
	p['d']="0111001110";
	p['e']="0111001100";
	p['f']="0111001000";
	p['g']="0111000000";
	p['a']="0110000000";
	p['b']="0100000000";
	p['C']="0010000000";
	p['D']="1111001110";
	p['E']="1111001100";
	p['F']="1111001000";
	p['G']="1111000000";
	p['A']="1110000000";
	p['B']="1100000000";
	int t;
	cin>>t;
	cin.ignore();
	string s;
	while(t--){
		getline(cin, s);
		s=" "+s;
		int cnt[10];
		memset(cnt, 0, sizeof(cnt));
		for(int q=0; q<s.size(); q++){
			for(int f=0; f<10; f++){
				if(p[s[q]][f]=='0'&&p[s[q+1]][f]=='1'){
					cnt[f]++;
				}
			}
		}
		cout<<cnt[0];
		for(int q=1; q<10; q++){
			cout<<" "<<cnt[q];
		}
		cout<<endl;
	}
}
