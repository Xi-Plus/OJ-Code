// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Node{
	int son,ans,from;
	bool leader,visit;
}node[50010];
int anslen,ansleader;
void dfs(int p){
	node[p].visit=true;
	if(node[p].from==node[node[p].son].from){
		if(node[p].ans>anslen){
			anslen=node[p].ans;
			ansleader=node[p].from;
		}
		return ;
	}
	node[node[p].son].ans=node[p].ans+1;
	node[node[p].son].from=node[p].from;
	dfs(node[p].son);
}
void dfs_circle(int p,int minp,int maxl){
	if(node[node[p].son].visit){
		if(maxl>anslen){
			anslen=maxl;
			ansleader=minp;
		}
		return ;
	}
	node[p].visit=true;
	dfs_circle(node[p].son,min(minp,node[p].son),maxl+1);
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int t,n,a,b;
	cin>>t;
	for(int cas=1;cas<=t;cas++){
		cin>>n;
		for(int q=1;q<=n;q++){
			node[q].leader=true;
			node[q].visit=false;
			node[q].ans=1;
			node[q].from=q;
		}
		for(int q=1;q<=n;q++){
			cin>>a>>b;
			node[a].son=b;
			node[b].leader=false;
		}
		anslen=0,ansleader=0;
		for(int q=1;q<=n;q++){
			if(node[q].leader) dfs(q);
		}
		for(int q=1;q<=n;q++){
			if(!node[q].visit)dfs_circle(q,q,1);
		}
		cout<<"Case "<<cas<<": "<<ansleader<<endl;
	}
}
