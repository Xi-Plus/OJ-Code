// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n,t,ans=0;
	vector<int> v1,v2;
	cin>>n;
	for(int q=0;q<n;q++){
		cin>>t;
		v1.push_back(t);
	}
	bool v=1;
	while(true){
		if(v){
			v2.clear();
			v2.push_back(v1[0]);
			int sz=v1.size();
			for(int q=1;q<sz;q++){
				if(v1[q]>v1[q-1])v2.push_back(v1[q]);
			}
		} else {
			v1.clear();
			v1.push_back(v2[0]);
			int sz=v2.size();
			for(int q=1;q<sz;q++){
				if(v2[q]>v2[q-1])v1.push_back(v2[q]);
			}
		}
		if(v1.size()==v2.size())break;
		ans++;
		v=!v;
	}
	cout<<ans<<endl;
}

