// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
bool dp[1002010];
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n;
	cin>>n;
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	int t;
	int sum=0;
	for(int q=1;q<=n;q++){
		cin>>t;
		sum+=t;
		for(int w=min(2000*q,1000000);w>=0;w--){
			dp[w+t]=max(dp[w+t],dp[w]);
		}
	}
	for(int q=sum/2;q>=0;q--){
		if(dp[q]){
			cout<<q<<" "<<sum-q<<endl;
			break;
		}
	}
}
