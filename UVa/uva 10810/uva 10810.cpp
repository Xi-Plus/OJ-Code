// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int MAX=500010;
int bit[MAX];
int lowerbit(int x){
	return x&-x;
}
void add(int x){
	while(x<=MAX){
		bit[x]++;
		x+=lowerbit(x);
	}
}
int sum(int x){
	int ans=0;
	while(x){
		ans+=bit[x];
		x-=lowerbit(x);
	}
	return ans;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n,t;
	while(cin>>n,n){
		vector<int> v,v2;
		for(int w=0;w<n;w++){
			cin>>t;
			v.push_back(t);
			v2.push_back(t);
		}
		sort(v.begin(),v.end());
		for(int w=0;w<n;w++){
			v2[w]=lower_bound(v.begin(),v.end(),v2[w])-v.begin()+1;
		}
		long long ans=0;
		memset(bit,0,sizeof(bit));
		for(int w=0;w<n;w++){
			ans+=w-sum(v2[w]);
			add(v2[w]);
		}
		cout<<ans<<endl;
	}
}
