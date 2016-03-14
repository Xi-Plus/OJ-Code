// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int ans[4],query[4];
	int anscnt[10],quecnt[10];
	int k,t;
	while(cin>>ans[0]>>ans[1]>>ans[2]>>ans[3]){
		memset(anscnt,0,sizeof(anscnt));
		for(int q=0;q<4;q++)anscnt[ans[q]]++;
		cin>>k;
		while(k--){
			int A=0,B=0;
			memset(quecnt,0,sizeof(quecnt));
			for(int q=0;q<4;q++){
				cin>>t;
				if(ans[q]==t)A++;
				quecnt[t]++;
			}
			for(int q=0;q<=9;q++){
				B+=min(anscnt[q],quecnt[q]);
			}
			B-=A;
			cout<<A<<"A"<<B<<"B"<<endl;
		}
	}
}
