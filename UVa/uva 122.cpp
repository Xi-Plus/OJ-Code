// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Node{
    int parent,left,right,value;
    bool valid;
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	char c;
	while(cin>>c){
//		cout<<"input:"<<c<<endl;
		vector<Node>node;
		node.push_back({-1,-1,-1,0,false});
		int used=0;
		bool x=true;
		while(cin>>c){
//			cout<<"input:"<<c<<endl;
			if(c==')')break;
			int num=0,sign=1;
			while(true){
//				cout<<"num="<<num<<endl;
				if(c==',')break;
				else if(c=='-')sign*=-1;
				else num=num*10+c-'0';
				cin>>c;
//				cout<<"input:"<<c<<" num="<<num<<" sign="<<sign<<endl;
			}
			num*=sign;
//			cout<<"num="<<num<<endl;
			int index=0,newid=-1;
			while(cin>>c){
//				cout<<"input:"<<c<<endl;
				if(c==')')break;
				if(c=='L'){
					if(node[index].left==-1){
						used++;
						node[index].left=used;
						node.push_back({index,-1,-1,0,false});
						index=used;
					}else {
						index=node[index].left;
					}
				}else if(c=='R'){
					if(node[index].right==-1){
						used++;
						node[index].right=used;
						node.push_back({index,-1,-1,0,false});
						index=used;
					}else {
						index=node[index].right;
					}
				}
			}
			if(node[index].valid)x=false;
			node[index].value=num;
			node[index].valid=true;
//			cout<<index<<" "<<node[index].value<<endl;
			cin>>c;
		}
		vector<int>ans;
		queue<int>bfs;
		bfs.push(0);
		while(!bfs.empty()){
			int index=bfs.front();
			bfs.pop();
			if(node[index].valid==false){
				x=false;
				break;
			}
			ans.push_back(node[index].value);
	        if(node[index].left!=-1)bfs.push(node[index].left);
	        if(node[index].right!=-1)bfs.push(node[index].right);
		}
		if(x){
			cout<<ans[0];
			int size=ans.size();
			for(int q=1;q<size;q++){
				cout<<" "<<ans[q];
			}
			cout<<endl;
		}else cout<<"not complete"<<endl;
	}
}

