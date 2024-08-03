// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int v[1010];
	memset(v,0x3f,sizeof(v));
	v[1]=0;
	for(int q=1;q<=200;q++){
		v[q]=min(v[q],v[q-1]+1);
		v[q*2]=v[q]+1;
		v[q*3]=v[q]+2;
		v[q*5]=v[q]+3;
	}
	for(int q=201;q<=334;q++){
		v[q]=min(v[q],v[q-1]+1);
		v[q*2]=v[q]+1;
		v[q*3]=v[q]+2;
	}
	for(int q=335;q<=500;q++){
		v[q]=min(v[q],v[q-1]+1);
		v[q*2]=v[q]+1;
	}
	for(int q=501;q<=1000;q++){
		v[q]=min(v[q],v[q-1]+1);
	}
	int n;
	while(cin>>n,n){
		cout<<v[n]<<endl;
	}
}
