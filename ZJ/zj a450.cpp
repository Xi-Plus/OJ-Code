// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n,q;
	cin>>n>>q;
	vector<int> v;
	int t;
	while(n--){
		cin>>t;
		v.push_back(t);
	}
	sort(v.begin(),v.end());
	int a,b;
	while(q--){
		cin>>a>>b;
		int ans=upper_bound(v.begin(),v.end(),b)-lower_bound(v.begin(),v.end(),a);
		if(ans)cout<<ans<<endl;
		else cout<<"The candies are too short"<<endl;
	}
}
