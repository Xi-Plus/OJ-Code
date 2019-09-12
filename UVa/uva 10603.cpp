#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int HALF_INT_MAX=INT_MAX/2;
int dp[205][205][205];
int a, b, c, d;
void dfs(int na, int nb, int nc){
//	cout<<"   "<<na<<" "<<nb<<" "<<nc<<" "<<dp[na][nb][nc]<<endl;
	if(na>0){
		// a to b
		if(na+nb<=b){
			if(dp[na][nb][nc]+na<dp[0][na+nb][nc]){
//				cout<<"a-b "<<na<<" "<<nb<<" "<<nc<<endl;
				dp[0][na+nb][nc]=dp[na][nb][nc]+na;
				dfs(0, na+nb, nc);
			}
		}else{
			if(b-nb>0&&dp[na][nb][nc]+b-nb<dp[na-(b-nb)][b][nc]){
//				cout<<"a-b "<<na<<" "<<nb<<" "<<nc<<endl;
				dp[na-(b-nb)][b][nc]=dp[na][nb][nc]+b-nb;
				dfs(na-(b-nb), b, nc);
			}
		}
		// a to c
		if(na+nc<=c){
			if(dp[na][nb][nc]+na<dp[0][nb][na+nc]){
//				cout<<"a-c "<<na<<" "<<nb<<" "<<nc<<endl;
				dp[0][nb][na+nc]=dp[na][nb][nc]+na;
				dfs(0, nb, na+nc);
			}
		}else{
			if(c-nc>0&&dp[na][nb][nc]+c-nc<dp[na-(c-nc)][nb][c]){
//				cout<<"a-c "<<na<<" "<<nb<<" "<<nc<<endl;
				dp[na-(c-nc)][nb][c]=dp[na][nb][nc]+c-nc;
				dfs(na-(c-nc), nb, c);
			}
		}
	}
	if(nb>0){
		// b to a
		if(nb+na<=a){
			if(dp[na][nb][nc]+nb<dp[na+nb][0][nc]){
//				cout<<"b-a "<<na<<" "<<nb<<" "<<nc<<endl;
				dp[na+nb][0][nc]=dp[na][nb][nc]+nb;
				dfs(na+nb, 0, nc);
			}
		}else{
			if(a-na>0&&dp[na][nb][nc]+a-na<dp[a][nb-(a-na)][nc]){
//				cout<<"b-a "<<na<<" "<<nb<<" "<<nc<<endl;
				dp[a][nb-(a-na)][nc]=dp[na][nb][nc]+a-na;
				dfs(a, nb-(a-na), nc);
			}
		}
		// b to c
		if(nb+nc<=c){
			if(dp[na][nb][nc]+nb<dp[na][0][nb+nc]){
//				cout<<"b-c "<<na<<" "<<nb<<" "<<nc<<endl;
				dp[na][0][nb+nc]=dp[na][nb][nc]+nb;
				dfs(na, 0, nb+nc);
			}
		}else{
			if(c-nc>0&&dp[na][nb][nc]+c-nc<dp[na][nb-(c-nc)][c]){
//				cout<<"b-c "<<na<<" "<<nb<<" "<<nc<<endl;
				dp[na][nb-(c-nc)][c]=dp[na][nb][nc]+c-nc;
				dfs(a, nb-(c-nc), nc);
			}
		}
	}
	if(nc){
		// c to a
		if(nc+na<=a){
			if(dp[na][nb][nc]+nc<dp[na+nc][b][0]){
//				cout<<"c-a "<<na<<" "<<nb<<" "<<nc<<endl;
				dp[na+nc][b][0]=dp[na][nb][nc]+nc;
				dfs(na+nc, b, 0);
			}
		}else{
			if(a-na>0&&dp[na][nb][nc]+a-na<dp[a][nb][nc-(a-na)]){
//				cout<<"c-a "<<na<<" "<<nb<<" "<<nc<<endl;
				dp[a][nb][nc-(a-na)]=dp[na][nb][nc]+a-na;
				dfs(a, nb, nc-(a-na));
			}
		}
		// c to b
		if(nc+nb<=b){
			if(dp[na][nb][nc]+nc<dp[na][nc+nb][0]){
//				cout<<"c-b "<<na<<" "<<nb<<" "<<nc<<endl;
				dp[na][nc+nb][0]=dp[na][nb][nc]+nc;
				dfs(na, nc+nb, 0);
			}
		}else{
			if(b-nb>0&&dp[na][nb][nc]+b-nb<dp[na][b][nc-(b-nb)]){
//				cout<<"c-b "<<na<<" "<<nb<<" "<<nc<<endl;
				dp[na][b][nc-(b-nb)]=dp[na][nb][nc]+b-nb;
				dfs(na, b, nc-(b-nb));
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d;
		for(int q=0; q<=a; q++){
			for(int w=0; w<=b; w++){
				for(int e=0; e<=c; e++){
					dp[q][w][e]=HALF_INT_MAX;
				}
			}
		}
		dp[0][0][c]=0;
		dfs(0, 0, c);
		int ans=INT_MAX;
		for(int d2=d; d2>=0; d2--){
			for(int q=0; q<=b; q++){
				for(int w=0; w<=c; w++){
					ans=min(ans, dp[d][q][w]);
				}
			}
			for(int q=0; q<=a; q++){
				for(int w=0; w<=c; w++){
					ans=min(ans, dp[q][d][w]);
				}
			}
			for(int q=0; q<=a; q++){
				for(int w=0; w<=b; w++){
					ans=min(ans, dp[q][w][d]);
				}
			}
			if(ans!=INT_MAX){
				cout<<ans<<" "<<d<<endl;
				break;
			}
		}
	}
}
