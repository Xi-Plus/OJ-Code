// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n;
	string s;
	long long ans=0;
	cin>>n;
	while(n--){
		cin>>s;
		bool a=s[2]==s[3];
		bool b=s[3]==s[4];
		bool c=s[4]==s[5];
		if(a){
			if(b){
				if(c)ans+=2000;
				else ans+=1000;
			}else {
				if(c)ans+=1500;
			}
		}else{
			if(b&&c)ans+=1000;
		}
	}
	cout<<ans<<endl;
}
