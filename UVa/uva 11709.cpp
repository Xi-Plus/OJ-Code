// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Node{
	bool visit;
	vector<int> side1,side2;
}node[1010];
stack<int> stamp;
void dfs_stamp(int now){
	node[now].visit=true;
	for(auto next:node[now].side2){
		if(!node[next].visit){
			dfs_stamp(next);
		}
	}
	stamp.push(now);
}
void dfs_scc(int now){
	node[now].visit=true;
	for(auto next:node[now].side1){
		if(!node[next].visit){
			dfs_scc(next);
		}
	}
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int P,T;
	string s,s2;
	while(cin>>P>>T,P||T){
		map<string,int> name2id;
		vector<string> id2name;
		cin.ignore();
		for(int q=0;q<P;q++){
			getline(cin,s);
			name2id[s]=q;
			id2name.push_back(s);
		}
		for(int q=0;q<P;q++){
			node[q].visit=false;
			node[q].side1.clear();
			node[q].side2.clear();
		}
		while(T--){
			getline(cin,s);
			getline(cin,s2);
			int id1,id2;
			id1=name2id[s];
			id2=name2id[s2];
			node[id1].side1.push_back(id2);
			node[id2].side2.push_back(id1);
		}
		for(int q=0;q<P;q++){
			if(!node[q].visit){
				dfs_stamp(q);
			}
		}
		for(int q=0;q<P;q++){
			node[q].visit=false;
		}
		int scccnt=0;
		while(!stamp.empty()){
			int now=stamp.top();
			stamp.pop();
			if(!node[now].visit){
				scccnt++;
				dfs_scc(now);
			}
		}
		cout<<scccnt<<endl;
	} 
}
