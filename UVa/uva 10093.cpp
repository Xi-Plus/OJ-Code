#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string chars="";
	map<char, int> cidx;
	for(int q=0; q<10; q++){
		chars+=(char)('0'+q);
		cidx['0'+q]=q;
	}
	for(int q=0; q<26; q++){
		chars+=(char)('A'+q);
		cidx['A'+q]=q+10;
	}
	for(int q=0; q<26; q++){
		chars+=(char)('a'+q);
		cidx['a'+q]=q+36;
	}
	string s;
	while(cin>>s){
		int ans=2;
		if(s[0]=='+'||s[0]=='-'){
			s=s.substr(1);
		}
		while(ans<=62){
			bool out=false;
			for(int q=0; q<s.size(); q++){
				if(cidx[s[q]]>=ans){
					out=true;
					break;
				}
			}
			if(out){
				ans++;
				continue;
			}
			int sum=0;
			for(int q=0; q<s.size(); q++){
				sum*=ans;
				sum+=cidx[s[q]];
				sum%=(ans-1);
			}
			if(sum==0){
				break;
			}
			ans++;
		}
		if(ans==63){
			cout<<"such number is impossible!"<<endl;
		}else{
			cout<<ans<<endl;
		}
	}
}
