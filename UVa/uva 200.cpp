// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<string> v;
struct Ship{
	vector<char> son;
	int index;
	bool top;
	bool visit;
}ship[128];
struct Ans{
	char c;
	int index;
};
vector<Ans> ans;
bool cmp(Ans a,Ans b){
	return a.index<b.index;
}
int dfscount=0;
void dfs(int p,int liml,int limr){
	dfscount++;
	int l=liml,r=liml;
	while(l<=limr&&r<limr){
		if(v[r][p]!=v[r+1][p]){
			ship[int(v[r][p])].son.push_back(v[r+1][p]);
			ship[int(v[r+1][p])].top=0;
			if(l<r&&p+1<=int(v[l].size()))dfs(p+1,l,r);
			l=r+1;
			r=l;
		}else {
			if(int(v[l].size())<=p+1){
				l++;
			}
			r++;
		}
	}
	if(l<r){
		dfs(p+1,l,r);
	}
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n;
	string s;
	while(cin>>s){
		v.clear();
		ans.clear();
		for(int q='0';q<='z';q++){
			ship[q].son.clear();
			ship[q].index=-1;
			ship[q].top=1;
			ship[q].visit=0;
		}
		n=1;
		v.push_back(s);
		while(cin>>s,s!="#"){
			n++;
			v.push_back(s);
		}
		dfs(0,0,n-1);
		int c=0;
		for(int q='0';q<='z';q++){
			if(!ship[q].son.empty()&&ship[q].top){
				c=q;
				break;
			}
		}
		ship[c].index=0;
		queue<char> bfs;
		bfs.push(c);
		while(!bfs.empty()){
			int now=bfs.front();
			ship[now].visit=1;
			bfs.pop();
			for(int i:ship[now].son){
				ship[i].index=max(ship[i].index,ship[now].index+1);
				if(!ship[i].visit)bfs.push(i);
			}
		}
		vector<Ans> ans;
		for(int q='0';q<='z';q++){
			if(ship[q].index!=-1){
				ans.push_back({char(q),ship[q].index});
			}
		}
		sort(ans.begin(),ans.end(),cmp);
		for(auto i:ans){
			cout<<i.c;
		}
		cout<<endl;
	}
}
