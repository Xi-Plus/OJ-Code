// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Side{
	bool visit;
	int a,b;
};
struct Node{
	vector<pair<int,bool>> side;
}node[51];
vector<Side> side;
vector<pair<int,int>> ans;
void dfs(int p){
	int sz=node[p].side.size();
	for(int q=0;q<sz;q++){
		if(!side[node[p].side[q].first].visit){
			side[node[p].side[q].first].visit=true;
			if(node[p].side[q].second){
				dfs(side[node[p].side[q].first].a);
				ans.push_back(make_pair(side[node[p].side[q].first].b,
										side[node[p].side[q].first].a));
			}
			else {
				dfs(side[node[p].side[q].first].b);
				ans.push_back(make_pair(side[node[p].side[q].first].a,
										side[node[p].side[q].first].b));
			}
		}
	}
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int t,n,a,b;
	cin>>t;
	for(int cas=0;cas<t;cas++){
		ans.clear();
		for(int q=1;q<=50;q++){
			node[q].side.clear();
		}
		cin>>n;
		while(n--){
			cin>>a>>b;
			node[a].side.push_back(make_pair(side.size(),false));
			node[b].side.push_back(make_pair(side.size(),true));
			side.push_back({false,a,b});
		}
		for(int q=1;q<=50;q++){
			if(node[q].side.size()){
				dfs(q);
				break;
			}
		}
		bool x=1;
		for(int q=1;q<=50;q++){
			if(node[q].side.size()%2==1){
				x=0;
				break;
			}
		}
		for(auto i:side){
			if(!i.visit){
				x=0;
				break;
			}
		}
		if(cas)cout<<endl;
		cout<<"Case #"<<cas+1<<endl;
		if(x){
			for(auto i:ans){
				cout<<i.second<<" "<<i.first<<endl;
			}
		}else {
			cout<<"some beads may be lost"<<endl;
		}
	}
}
