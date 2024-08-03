// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Node{
	int visit,low;
	vector<int> son;
}node[110];
int ans;
void dfs(int i,int p,int d){
	node[i].visit=node[i].low=d;
	bool ap=false;
	int child=0;
	for(int s:node[i].son){
		if(s==p)continue;
		if(node[s].visit){
			node[i].low=min(node[i].low,node[s].visit);
		} else {
			child++;
			dfs(s,i,d+1);
			node[i].low=min(node[i].low,node[s].low);
			if(node[s].low>=node[i].visit)ap=true;
		}
	}
	if((i==p&&child>1)||(i!=p&&ap)){
		ans++;
	}
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n,p,t;
	string s;
	while(cin>>n,n){
		for(int q=1;q<=n;q++){
			node[q].son.clear();
			node[q].visit=0;
		}
		ans=0;
		while(cin>>p,p){
			cin.get();
			getline(cin,s);
			stringstream ss(s);
			while(ss>>t){
				node[p].son.push_back(t);
				node[t].son.push_back(p);
			}
		}
		dfs(1,1,1);
		cout<<ans<<endl;
	}
}
