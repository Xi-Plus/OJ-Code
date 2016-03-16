// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int t;
	cin>>t;
	string s;
	while(t--){
		cin>>s;
		int sz=s.size();
		int sum=0;
		for(int q=0;q<sz;q++){
			sum+=s[sz-q-1]*(q%2+1);
		}
		if(sum%3)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
}
