// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
bool dp[10110];
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int m,n;
	cin>>m>>n;
	while(m--){
		int halfsum=0;
		int v[n];
		for(int q=0;q<n;q++){
			cin>>v[q];
			halfsum+=v[q];
		}
		if(halfsum%2){
			cout<<"No"<<endl;
			continue;
		}
		halfsum/=2;
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int q=0;q<n;q++){
			for(int w=10000;w>=0;w--){
				dp[w+v[q]]=max(dp[w+v[q]],dp[w]);
			}
			if(dp[halfsum]) break;
		}
		if(dp[halfsum]){
			cout<<"Yes"<<endl;
		}else {
			cout<<"No"<<endl;
		}
	}
}