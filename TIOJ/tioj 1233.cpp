// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
bool v[520][520]={0};
void dfs(int x,int y){
	v[x][y]=0;
	if(v[x-1][y-1]) dfs(x-1,y-1);
	if(v[x-1][y]) dfs(x-1,y);
	if(v[x-1][y+1]) dfs(x-1,y+1);
	if(v[x][y-1]) dfs(x,y-1);
	if(v[x][y+1]) dfs(x,y+1);
	if(v[x+1][y-1]) dfs(x+1,y-1);
	if(v[x+1][y]) dfs(x+1,y);
	if(v[x+1][y+1]) dfs(x+1,y+1);
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int m,n;
	cin>>m>>n;
	char c;
	for(int q=1;q<=m;q++){
		for(int w=1;w<=n;w++){
			cin>>c;
			v[q][w]=c-'0';
		}
	}
	int ans=0;
	for(int q=1;q<=m;q++){
		for(int w=1;w<=n;w++){
			if(v[q][w]==1){
				dfs(q,w);
				ans++;
			}
		}
	}
	int a[]={0,1,2,4,6,10,12,14,16,18,2147483647};
	for(int q=0;q<=11;q++){
		if(ans<=a[q]){
			cout<<q<<endl;
			break;
		}
	}
}