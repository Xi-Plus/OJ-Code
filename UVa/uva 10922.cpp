#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int n, n2, d;
	while(cin>>s, s!="0"){
		n=0;
		for(int q=0; q<s.size(); q++){
			n+=s[q]-'0';
		}
		d=1;
		while(n>9){
			n2=0;
			while(n){
				n2+=n%10;
				n/=10;
			}
			d++;
			n=n2;
		}
		if(n==9){
			cout<<s<<" is a multiple of 9 and has 9-degree "<<d<<"."<<endl;
		}else{
			cout<<s<<" is not a multiple of 9."<<endl;
		}
	}
}

