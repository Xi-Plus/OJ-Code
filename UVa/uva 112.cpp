// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Node{
    int parent,left,right,sum,parentsum;
	bool isleaf;
};
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n;
	char c;
	while(cin>>n){
		bool x=0;
		vector<Node>node;
		node.push_back({-1,-1,-1,0,0,false});
		int lastnode=0,used=0;
		bool sign=false;
		while(cin>>c){
			if(c=='('){
				sign=false;
				used++;
				if(node[lastnode].left==-1){
					node[lastnode].left=used;
					node[lastnode].parentsum+=node[lastnode].sum;
				}else {
					node[lastnode].right=used;
				}
				node.push_back({lastnode,-1,-1,0,node[lastnode].parentsum,true});
				lastnode=used;
			}else if(c==')'){
				if(!node[lastnode].isleaf
					&&node[ node[lastnode].left ].isleaf
					&&node[ node[lastnode].right ].isleaf
					&&n==node[lastnode].parentsum
					){
					x=1;
				}
				lastnode=node[lastnode].parent;
			}else {
				if(c=='-'){
					sign=true;
				}else {
					node[lastnode].isleaf=false;
					node[lastnode].sum*=10;
					if(sign)node[lastnode].sum-=c-'0';
					else node[lastnode].sum+=c-'0';
				}
			}
			if(lastnode==0)break;
		}
		if(x)cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}

