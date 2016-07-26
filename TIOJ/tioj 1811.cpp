// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N,L;
int H[100010],W[100010],dp[100010];
int solve(){
	dp[0]=0;
	for(int q=1;q<=N;q++){
		dp[q]=2147483647;
		for(int w=0;w<q;w++){
			int widsum=0,maxh=0;
			for(int e=w+1;e<=q;e++){
				widsum+=W[e];
				maxh=max(maxh,H[e]);
			}
			if(widsum>L) continue;
			dp[q]=min(dp[q],dp[w]+maxh);
		}
	}
	return dp[N];
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	cin>>N>>L;
	for(int q=0;q<N;q++){
		cin>>H[q]>>W[q];
	}
	cout<<solve<<endl;
}

