// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	string s;
	while(cin>>s){
		int i=0,sz=s.size();
		double n=0;
		if(s[0]=='-'){
			i++;
		}
		for(;s[i]!='.'&&i<sz;i++){
			n*=10;
			n+=s[i]-'0';
		}
		if(s[i]=='.'){
			i++;
		}
		for(int q=0;q<3;q++,i++){
			n*=10;
			n+=s[i]-'0';
		}
		n/=1000;
		if(s[0]=='-'){
			n*=-1;
		}
		cout<<fixed<<setprecision(6)<<n<<endl;
		cout<<fixed<<setprecision(2)<<n<<endl;
	}
}
