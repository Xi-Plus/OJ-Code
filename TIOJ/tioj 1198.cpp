// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int now[9],goal[9];
int bfs(int d,int x0,int y0,int ans){
	if(memcmp(now,goal,sizeof(now))==0)return ans;
//	if()
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int zero;
	for(int q=0;q<9;q++){
		cin>>now[q];
		if(now[q]==0)zero=q;
	}
	for(int q=0;q<9;q++) cin>>goal[q];
	cout<<bfs(0,zero/3,zero%3,0)<<endl;
	int a;
	cout<<a;
}