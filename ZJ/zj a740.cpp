// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
bool nisp[46341]={false};
int p[10000];
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	nisp[0]=nisp[1]=true;
	int i=2,j,k=0;
	while(i<46341){
		if(!nisp[i]){
			p[k++]=i;
			j=i*2;
			while(j<46341){
				nisp[j]=true;
				j+=i;
			}
		}
		i++;
	}
	int n;
	while(cin>>n){
		int ans=0;
		for(int q=0;q<k;q++){
			while(n%p[q]==0){
				ans+=p[q];
				n/=p[q];
			}
		}
		if(n!=1)ans+=n;
		cout<<ans<<endl;
	}
}
