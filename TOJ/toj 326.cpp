// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	string s;
	char c;
	while(cin>>s){
		stringstream ss(s);
		unsigned long long n=0;
		while(ss>>c&&c!='.'){
			n*=10;
			n+=c-'0';
		}
		int d=0;
		int dig=0;
		while(ss>>c){
			dig++;
			d*=10;
			d+=c-'0';
		}
		int mod=pow(10,dig);
		if(!n)cout<<"0";
		vector<bool> nd;
		while(n){
			nd.push_back(n%2);
			n/=2;
		}
		reverse(nd.begin(),nd.end());
		for(auto i:nd) cout<<i;
		if(d){
			cout<<".";
			vector<int> old;
			vector<bool> ans;
			int p=0;
			bool x=0;
			while(d){
				d*=2;
				p=0;
				x=0;
				for(auto i:old){
					if(d==i){
						x=1;
						break;
					}
					p++;
				}
				if(x){
					break;
				}
				old.push_back(d);
				ans.push_back(d/mod);
				d%=mod;
			}
			if(x){
				for(int q=0;q<p;q++)cout<<ans[q];
				cout<<"(";
				int sz=ans.size();
				for(int q=p;q<sz;q++)cout<<ans[q];
				cout<<")";
			}else {
				for(auto i:ans)cout<<i;
			}
		}
		cout<<endl;
	}
}
