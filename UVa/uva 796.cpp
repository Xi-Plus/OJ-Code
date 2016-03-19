// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Node{
	int visit,low;
	vector<int> son;
}node[110];
struct Ans{
	int a,b;
};
bool cmp(Ans a,Ans b){
	if(a.a==b.a)return a.b<b.b;
	return a.a<b.a;
}
vector<Ans> ans;
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
			if(node[s].low>node[i].visit){
				ans.push_back({min(i,s),max(i,s)});
			} 
		}
	}
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n,p,tn,t;
	char c;
	while(cin>>n){
		if(n==0){
			cout<<"0 critical links"<<endl<<endl;
			continue;
		}
		for(int q=0;q<n;q++){
			node[q].son.clear();
			node[q].visit=0;
		}
		ans.clear();
		for(int q=0;q<n;q++){
			cin>>p>>c>>tn>>c;
			while(tn--){
				cin>>t;
				node[p].son.push_back(t);
			}
		}
		for(int q=0;q<n;q++){
			if(node[q].visit==0){
				dfs(q,q,1);
			}
		}
		sort(ans.begin(),ans.end(),cmp);
		cout<<ans.size()<<" critical links"<<endl;
		for(auto i:ans){
			cout<<i.a<<" - "<<i.b<<endl;
		}
		cout<<endl;
	}
}
