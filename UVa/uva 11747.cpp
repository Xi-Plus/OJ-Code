#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int leader[1005];
int getlea(int q){
	if(leader[q]==q){
		return q;
	}
	return leader[q]=getlea(leader[q]);
}
bool same(int a, int b){
	return getlea(a)==getlea(b);
}
void merge(int a, int b){
	leader[getlea(b)]=getlea(a);
}
struct Edge{
	int a, b, w;
};
Edge edge[25005];
bool cmp(Edge a, Edge b){
	return a.w<b.w;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	while(cin>>n>>m, n||m){
		for(int q=0; q<n; q++){
			leader[q]=q;
		}
		for(int q=0; q<m; q++){
			cin>>edge[q].a>>edge[q].b>>edge[q].w;
		}
		sort(edge, edge+m, cmp);
		vector<int> ans;
		for(int q=0; q<m; q++){
			if(!same(edge[q].a, edge[q].b)){
				merge(edge[q].a, edge[q].b);
			}else{
				ans.push_back(edge[q].w);
			}
		}
		if(ans.size()){
			sort(ans.begin(), ans.end());
			cout<<ans[0];
			for(int q=1; q<ans.size(); q++){
				cout<<" "<<ans[q];
			}
			cout<<endl;
		}else{
			cout<<"forest"<<endl;
		}
	}
}
