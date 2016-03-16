// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Side{
	int p,w;
};
struct Point{
	int w;
	vector<Side> side;
}point[110];
void dfs(int now){
	for(auto i:point[now].side){
		if(point[i.p].w>max(point[now].w,i.w)){
			point[i.p].w=max(point[now].w,i.w);
			dfs(i.p);
		}
	}
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int C,S,Q;
	int a,b,w;
	for(int cas=1;;cas++){
		cin>>C>>S>>Q;
		if(!C&&!S&&!Q) break;
		for(int q=1;q<=C;q++) point[q].side.clear();
		while(S--){
			cin>>a>>b>>w;
			point[a].side.push_back({b,w});
			point[b].side.push_back({a,w});
		}
		if(cas>1)cout<<endl;
		cout<<"Case #"<<cas<<endl;
		while(Q--){
			for(int q=1;q<=C;q++) point[q].w=2147483647;
			cin>>a>>b;
			point[a].w=0;
			dfs(a);
			if(point[b].w==2147483647) cout<<"no path"<<endl;
			else cout<<point[b].w<<endl;
		}
	}
}
