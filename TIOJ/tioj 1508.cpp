// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n;
int v[100];
int halfsum=0;
bool ans=0;
void dfs(int index,int suma,int sumb){
	if(ans)return ;
	if(suma==halfsum||sumb==halfsum){
		ans=1;
		return ;
	}
	else if(suma>halfsum||sumb>halfsum) return;
	if(index>=n) return;
	dfs(index+1,suma+v[index],sumb);
	dfs(index+1,suma,sumb+v[index]);
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int m;
	cin>>m>>n;
	while(m--){
		halfsum=0;
		ans=0;
		for(int q=0;q<n;q++){
			cin>>v[q];
			halfsum+=v[q];
		}
		if(halfsum%2){
			cout<<"No"<<endl;
			continue;
		}
		halfsum/=2;
		sort(v,v+n,cmp);
		dfs(1,0,0);
		if(ans){
			cout<<"Yes"<<endl;
		}else {
			cout<<"No"<<endl;
		}
	}
}