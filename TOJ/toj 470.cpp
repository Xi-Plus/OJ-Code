#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int dp[1000005][2];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, c;
	while(cin>>n){
		dp[0][0]=0;
		dp[0][1]=0;
		cin>>c;
		dp[1][0]=c;
		dp[1][1]=0;
		for(int q=2; q<=n; q++){
			cin>>c;
			dp[q][0] = max(max(dp[q-2][0],dp[q-2][1]),dp[q-1][1])+c;
			dp[q][1] = max(dp[q-1][0], dp[q-1][1]);
		}
		cout<<max(dp[n][0], dp[n][1])<<endl;
	}
}

