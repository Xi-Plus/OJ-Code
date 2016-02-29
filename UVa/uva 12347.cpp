// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Node{
    int parent,left,right,value;
};
vector<Node>node;
void dfs(int index){
	if(node[index].left!=-1)dfs(node[index].left);
	if(node[index].right!=-1)dfs(node[index].right);
	cout<<node[index].value<<endl;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n,lastnode,used=0;
	cin>>n;
	node.push_back({-1,-1,-1,n});
	while(cin>>n){
		used++;
		lastnode=0;
		while(true){
			if(n<node[lastnode].value){
				if(node[lastnode].left==-1){
					node[lastnode].left=used;
					break;
				}
				else lastnode=node[lastnode].left;
			}else {
				if(node[lastnode].right==-1){
					node[lastnode].right=used;
					break;
				}
				lastnode=node[lastnode].right;
			}
		}
		node.push_back({lastnode,-1,-1,n});
	}
	dfs(0);
}

