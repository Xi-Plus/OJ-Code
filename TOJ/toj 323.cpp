// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n;
int v[100010];
int LIS(){
	vector<int> lis;
	lis.push_back(v[0]);
	for(int q=1;q<n;q++){
		if(v[q]>lis.back()){
			lis.push_back(v[q]);
		}else {
			lis[lower_bound(lis.begin(),lis.end(),v[q])-lis.begin()]=v[q];
		}
	}
	return lis.size();
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int k;
	cin>>n>>k;
	int ans[n+1];
	int t;
	for(int q=1;q<=n;q++){
		cin>>t;
		ans[t]=q;
	}
	while(k--){
		for(int q=0;q<n;q++){
			cin>>t;
			v[q]=ans[t];
		}
		cout<<LIS()<<endl;
	}
}
