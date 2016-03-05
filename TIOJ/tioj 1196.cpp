// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n;
	cin>>n;
	int v[n+1][n+1],dp[n+1][n+1];
	char c;
	for(int q=1;q<=n;q++){
		for(int w=1;w<=n;w++){
			cin>>c;
			switch(c){
				case 'X':
					v[q][w]=-1000000;
					break;
				default:
					v[q][w]=c-'0';
			}
		}
	}
	for(int q=0;q<=n;q++){
		dp[0][q]=-1000000;
		dp[q][0]=-1000000;
	}
	v[1][1]=0;
	v[n][n]=0;
	dp[0][1]=0;
	dp[1][0]=0;
	for(int q=1;q<=n;q++){
		for(int w=1;w<=n;w++){
			dp[q][w]=max(dp[q-1][w],dp[q][w-1])+v[q][w];
		}
	}
	if(dp[n][n]<0){
		cout<<"X"<<endl;
	}else {
		cout<<dp[n][n]<<endl;
	}
}