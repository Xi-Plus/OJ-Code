// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int v[50010];
int find(int n){
	if(n==v[n])return n;
	return v[n]=find(v[n]);
}
bool bfs(int a,int b){
	a=find(a);
	b=find(b);
	v[b]=a;
	if(a==b)return 0;
	return 1;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n,m;
	int cas=0;
	while(cin>>n>>m,n||m){
		for(int q=1;q<=n;q++){
			v[q]=q;
		}
		int ans=n;
		while(m--){
			int a,b;
			cin>>a>>b;
			ans-=bfs(a,b);
		}
		cout<<"Case "<<++cas<<": "<<ans<<endl;
	}
}
