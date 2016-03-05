// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
bool dp[10110];
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int m,n,t;
	cin>>m>>n;
	while(m--){
		int halfsum=0;
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int q=0;q<n;q++){
			cin>>t;
			for(int w=10000;w>=0;w--){
				dp[w+t]=max(dp[w+t],dp[w]);
			}
			halfsum+=t;
		}
		if(halfsum%2){
			cout<<"No"<<endl;
			continue;
		}
		halfsum/=2;
		if(dp[halfsum]){
			cout<<"Yes"<<endl;
		}else {
			cout<<"No"<<endl;
		}
	}
}