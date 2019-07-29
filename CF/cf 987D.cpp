#include<bits/stdc++.h>
using namespace std;
int town_goods[100005];
vector<int> G[100005];
vector<int> goods_in_town[105];
priority_queue<int, vector<int>, greater<int> > dis_get_goods[100005];
bool visited[100005];
int main() {
	int n,m,s,k;
	cin>>n>>m>>k>>s;
	for(int q=1; q<=n; q++){
		cin>>town_goods[q];
		goods_in_town[town_goods[q]].push_back(q);
	}
	int a,b;
	while(m--){
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int good=1;good<=k;good++){
		queue<int> now_town;
		memset(visited, 0, sizeof(visited));
		int now_dis = 0;
		for(auto town:goods_in_town[good]){
			now_town.push(town);
			dis_get_goods[town].push(0);
			visited[town]=1;
		}
		while(now_town.size()){
			queue<int> new_town;
			now_dis++;
			while(now_town.size()){
				for(auto target:G[now_town.front()]){
					if(!visited[target]){
						dis_get_goods[target].push(now_dis);
						new_town.push(target);
						visited[target]=true;
					}
				}
				now_town.pop();
			}
			while(new_town.size()){
				now_town.push(new_town.front());
				new_town.pop();
			}
		}
	}
	for(int town=1; town<=n; town++){
		int ans =0;
		
		for(int q=1; q<=s; q++){
			ans+=dis_get_goods[town].top();
			dis_get_goods[town].pop();
		}
		cout<<ans<<" ";
	}
	cout<<endl;
}
