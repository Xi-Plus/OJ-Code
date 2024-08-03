// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Node{
    int parent,left,right,value;
};
vector<Node>node;
//vector<int>ans;
int ans[200];
int leftd;
void dfs(int index,int d){
	int td=d+leftd;
//	if(ans.size()<td+1)ans.resize(td+1);
	ans[td]+=node[index].value;
	if(node[index].left!=-1)dfs(node[index].left,d-1);
	if(node[index].right!=-1)dfs(node[index].right,d+1);
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n,c=1;
	while(cin>>n&&n!=-1){
		node.clear();
		node.push_back({-2,-2,-2,n});
		int lastnode=0,used=0;
		leftd=0;
		bool isleft=true;
		while(cin>>n){
			if(node[lastnode].left==-2){
				if(n!=-1){
					used++;
					node.push_back({lastnode,-2,-2,n});
					node[lastnode].left=used;
					lastnode=used;
					if(isleft)leftd++;
				}else {
					isleft=false;
					node[lastnode].left=-1;
				}
			}else if(node[lastnode].right==-2){
				if(n!=-1){
					used++;
					node.push_back({lastnode,-2,-2,n});
					node[lastnode].right=used;
					lastnode=used;
				}else {
					node[lastnode].right=-1;
				}
			}
			while(lastnode!=0&&node[lastnode].left!=-2&&node[lastnode].right!=-2){
				lastnode=node[lastnode].parent;
			}
			if(lastnode==0&&node[lastnode].left!=-2&&node[lastnode].right!=-2)break;
		}
//		ans.clear();
		leftd=100;
		memset(ans,0,sizeof(ans));
		dfs(0,0);
		cout<<"Case "<<c++<<":"<<endl;
//		cout<<ans[0];
//		int size=ans.size();
//		for(int q=1;q<size;q++)cout<<" "<<ans[q];
		bool space=false;
		for(int q=0;q<200;q++){
			if(ans[q]!=0){
				if(space)cout<<" ";
				cout<<ans[q];
				space=true;
			}
		}
		cout<<endl<<endl;
	}
}

