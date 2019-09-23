#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int color[205];
vector<int> edges[205];
bool ans;
void dfs(int p, int nowc){
	for(int n:edges[p]){
		if(color[n]==0){
			color[n]=3-nowc;
			dfs(n, 3-nowc);
		}else{
			if(color[n]+nowc!=3){
				ans=false;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, a, b;
	while(cin>>n, n){
		cin>>m;
		memset(color, 0, sizeof(color));
		for(int q=0; q<n; q++){
			edges[q].clear();
		}
		for(int q=0; q<m; q++){
			cin>>a>>b;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		ans=true;
		dfs(0, 1);
		if(ans){
			cout<<"BICOLORABLE."<<endl;
		}else{
			cout<<"NOT BICOLORABLE."<<endl;
		}
	}
}
