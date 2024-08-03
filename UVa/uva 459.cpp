// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Node{
	bool visit;
	vector<char> son;
}node[128];
void dfs(char c){
	node[c].visit=true;
	for(auto i:node[c].son){
		if(!node[i].visit)dfs(i);
	}
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int t;
	cin>>t;
	char c;
	string s;
	while(t--){
		cin>>c;
		for(char q='A';q<=c;q++){
			node[q].visit=false;
			node[q].son.clear();
		}
		cin.get();
		while(getline(cin,s),s!=""){
			node[s[0]].son.push_back(s[1]);
			node[s[1]].son.push_back(s[0]);
		}
		int ans=0;
		for(char q='A';q<=c;q++){
			if(!node[q].visit){
				ans++;
				dfs(q);
			}
		}
		cout<<ans<<endl;
		if(t>0)cout<<endl;
	}
}
