// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string pre,in;
int used,p;
struct Node{
	int parent,left,right;
	char c;
};
vector<Node>node;
void create(int l,int r,int lastnode,bool side){
	int mid=-1;
	for(int q=l;q<=r;q++){
		if(in[q]==pre[p]){
			mid=q;
			break;
		}
	}
	used++;
	if(side)node[lastnode].left=used;
	else node[lastnode].right=used;
	node.push_back({lastnode,-1,-1,pre[p]});
	lastnode=used;
	if(mid!=l){
		p++;
		create(l,mid-1,lastnode,true);
	}
	if(mid!=r){
		p++;
		create(mid+1,r,lastnode,false);
	}
}
void dfs(int p){
	if(p==-1)return ;
	dfs(node[p].left);
	dfs(node[p].right);
	cout<<node[p].c;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>pre>>in){
		node.clear();
		node.push_back({-1,-1,-1,' '});
		used=0;
		p=0;
		create(0,pre.size()-1,0,true);
		dfs(1);
		cout<<endl;
	} 
}

