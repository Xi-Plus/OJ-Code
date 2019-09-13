#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int lx, ly;
	string x, y;
	while(cin>>lx>>x>>ly>>y){
		int dp[lx+1][ly+1];
		for(int q=0; q<=lx; q++){
			dp[q][0]=q;
		}
		for(int q=0; q<=ly; q++){
			dp[0][q]=q;
		}
		for(int q=1; q<=lx; q++){
			for(int w=1; w<=ly; w++){
				dp[q][w]=min(
					dp[q-1][w]+1,
					min(
						dp[q][w-1]+1,
						dp[q-1][w-1]+(x[q-1]!=y[w-1])
					)
				);
			}
		}
		cout<<dp[lx][ly]<<endl;
	}
}
