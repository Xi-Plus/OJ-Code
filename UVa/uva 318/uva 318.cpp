// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Side{
	int to;
	long long cost;
};
struct Line{
	int a,b;
	long long w;
};
struct Node{
	long long cost;
	vector<Side> side;
};
struct NodeDis{
	int p;
	long long cost;
    bool operator<(const NodeDis& rhs) const {
        return cost > rhs.cost;
    }
};
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	cout<<fixed<<setprecision(1);
	int N,S,a,b;
	long long w;
	for(int cas=1;;cas++){
		cin>>N>>S;
		if(N==0&&S==0)break;
		Node node[N+1];
		vector<Line> line;
		for(int q=1;q<=N;q++){
			node[q].cost=9223372036854775807LL;
			node[q].side.clear();
		}
		for(int q=0;q<S;q++){
			cin>>a>>b>>w;
			node[a].side.push_back({b,w});
			node[b].side.push_back({a,w});
			line.push_back({a,b,w});
		}
		node[1].cost=0;
		priority_queue<NodeDis> v;
		v.push({1,0});
		while(!v.empty()){
			auto p=v.top();
			v.pop();
			for(auto i:node[p.p].side){
				if(p.cost+i.cost<node[i.to].cost){
					node[i.to].cost=p.cost+i.cost;
					v.push({i.to,node[i.to].cost});
				}
			}
		}
		long long ans=0;
		int ansa=1,ansb=1;
		for(int q=1;q<=N;q++){
			if(node[q].cost*2>ans){
				ans=node[q].cost*2;
				ansa=q;
				ansb=q;
			}
		}
		for(auto l:line){
			long long t=(node[l.a].cost+node[l.b].cost+l.w);
			if(t>ans){
				ans=t;
				ansa=l.a;
				ansb=l.b;
			}
		}
		cout<<"System #"<<cas<<endl;
		if(ansa==ansb){
			cout<<"The last domino falls after "<<ans/2<<"."<<(ans%2?5:0)<<" seconds, at key domino "<<ansa<<"."<<endl;
		}else {
			if(ansa>ansb)swap(ansa,ansb);
			cout<<"The last domino falls after "<<ans/2<<"."<<(ans%2?5:0)<<" seconds, between key dominoes "<<ansa<<" and "<<ansb<<"."<<endl;
		}
		cout<<endl;
	}
}
