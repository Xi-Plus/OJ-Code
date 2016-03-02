// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m,k;
long long dp[1010][1010];
const long long mod=1000000007;
long long dfs(int step,int x_step){
	if(dp[step][x_step]!=-1) return dp[step][x_step];
	if(step==1){
		if(x_step==0)return 1;
		else return 0;
	}
	if(x_step==0){
		return dp[step][x_step]=((n-k-1)*dfs(step-1,0)%mod+dfs(step-1,k))%mod;
	}else {
		return dp[step][x_step]=(n-k+x_step-1)*dfs(step-1,x_step-1)%mod;
	}
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n>>m>>k;
		memset(dp,-1,sizeof(dp));
		cout<<dfs(m,k)%mod<<endl;
	}
}