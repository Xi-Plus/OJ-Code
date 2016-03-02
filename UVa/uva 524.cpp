// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
//          0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2
bool isp[]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0};
int n;
int A[16]={1};
bool used[17]={1,1};
void dfs(int i){
	if(i==n){
		if(isp[A[i-1]+1]){
			cout<<1;
			for(int q=1;q<n;q++){
				cout<<" "<<A[q];
			}
			cout<<endl;
		}
	}else {
		for(int q=2;q<=n;q++){
			if(!used[q]&&isp[A[i-1]+q]){
				A[i]=q;
				used[q]=1;
				dfs(i+1);
				used[q]=0;
			}
		}
	}
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int cas=0;
	while(cin>>n){
		if(cas)cout<<endl;
		cout<<"Case "<<++cas<<":"<<endl;
		dfs(1);
	}
}