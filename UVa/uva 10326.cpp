// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void del1(long long n){
	if(n!=1)cout<<n;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	long long n,t;
	while(cin>>n){
		if(n==0){
			cout<<"1 = 0"<<endl;
			continue;
		}
		long long v[n+1],v2[n+1];
		memset(v,0,sizeof(v));
		memset(v2,0,sizeof(v));
		v[0]=1;
		for(int q=0;q<n;q++){
			cin>>t;
			v2[0]=0;
			for(int w=0;w<n;w++){
				v2[w+1]=v[w];
			}
			for(int w=0;w<n;w++){
				v2[w]+=v[w]*(-t);
			}
			for(int w=0;w<=n;w++){
				v[w]=v2[w];
			}
		}
		if(n>=2){
			del1(abs(v[n]));
			cout<<"x^"<<n;
		}
		for(int w=n-1;w>=2;w--){
			if(v[w]==0)continue;
			cout<<" "<<(v[w]>=0?"+":"-")<<" ";
			del1(abs(v[w]));
			cout<<"x^"<<w;
		}
		if(v[1]!=0){
			if(n>1)cout<<" "<<(v[1]>=0?"+":"-")<<" ";
			del1(abs(v[1]));
			cout<<"x";
		}
		if(n>0)cout<<" "<<(v[0]>=0?"+":"-")<<" ";
		cout<<abs(v[0])<<" = 0";
		cout<<endl;
	}
}
