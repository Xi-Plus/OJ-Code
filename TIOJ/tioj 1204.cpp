// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string pre,in;
int used,lastnode,root;
struct Node{
	int parent,left,right,value;
};
vector<Node>node;
void add(int t){
	used++;
	if(t<node[lastnode].value){
		while(node[lastnode].parent!=-1&&t<node[node[lastnode].parent].value){
			lastnode=node[lastnode].parent;
		}
		node.push_back({node[lastnode].parent,lastnode,-1,t});
		if(node[lastnode].parent==-1)root=used;
		else node[node[lastnode].parent].right=used;
		node[lastnode].parent=used;
	}else {
		node[lastnode].right=used;
		node.push_back({lastnode,-1,-1,t});
	}
	lastnode=used;
}
void dfs(int p){
	if(p==-1)return ;
	cout<<node[p].value<<" ";
	dfs(node[p].left);
	dfs(node[p].right);
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n,t;
	while(cin>>n&&n){
		node.clear();
		cin>>t;
		node.push_back({-1,-1,-1,t});
		used=0;
		lastnode=0;
		root=0;
		for(int q=1;q<n;q++){
			cin>>t;
			add(t);
		}
		dfs(root);
		cout<<endl;
	} 
}

