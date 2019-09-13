#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool visited[205][205];
int jug[3], d, ans, change;
struct Node{
	int v[3];
	int cost;
	bool operator<(const Node& rhs) const {
		return cost > rhs.cost;
	}
};

void bfs(){
	priority_queue<Node>que;
	memset(visited, 0, sizeof(visited));
	Node t=Node({0, 0, jug[2], 0});
	visited[0][0]=true;
	que.push(t);
	while(!que.empty()){
		t=que.top();
		que.pop();
		for(int q=0; q<3; q++){
			if(t.v[q]==d){
				ans=min(ans, t.cost);
				break;
			}
			for(int w=0; w<3; w++){
				if(q!=w){
					change=min(t.v[q], jug[w]-t.v[w]);
					if(change){
						Node t2=t;
						t2.v[q]-=change;
						t2.v[w]+=change;
						t2.cost+=change;
						if(!visited[t2.v[0]][t2.v[1]]){
							que.push(t2);
							visited[t2.v[0]][t2.v[1]]=true;
						}
					}
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>jug[0]>>jug[1]>>jug[2]>>d;
		ans=INT_MAX;
		d++;
		while(ans==INT_MAX){
			d--;
			ans=INT_MAX;
			bfs();
		}
		cout<<ans<<" "<<d<<endl;
	}
}
