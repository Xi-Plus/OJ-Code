// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Node{
	int visit,low;
	vector<int> son;
}node[110];
vector<int> ans;
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
		ans.push_back(i);
	}
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n,p;
	string s,s2;
	int cas=0;
	while(cin>>n,n){
		map<string,int> m;
		string m2[n+1];
		for(int q=1;q<=n;q++){
			cin>>s;
			m[s]=q;
			m2[q]=s;
			node[q].son.clear();
			node[q].visit=0;
		}
		cin>>p;
		while(p--){
			cin>>s>>s2;
			node[m[s]].son.push_back(m[s2]);
			node[m[s2]].son.push_back(m[s]);
		}
		ans.clear();
		for(int q=1;q<=n;q++){
			if(!node[q].visit)dfs(q,q,1);
		}
		vector<string> sans;
		for(int i:ans) sans.push_back(m2[i]);
		sort(sans.begin(),sans.end());
		if(cas)cout<<endl;
		cout<<"City map #"<<++cas<<": "<<ans.size()<<" camera(s) found"<<endl;
		int endlcnt=0;
		for(string i:sans){
			cout<<i<<endl;
		}
	}
}
