// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n;
	int t=1;
	while(cin>>n){
		int v[n+1];
		for(int q=0;q<n;q++){
			cin>>v[q];
		}
		v[n]=0;
		long long ans=0,maxr=0,maxm=0;
		for(int q=0;q<=n;q++){
			if(v[q]<0){
				ans=max(ans,maxr);
				maxr*=v[q];
				maxm*=v[q];
				swap(maxr,maxm);
				if(maxm==0) maxm=v[q];
				if(maxr<0) maxr=0;
			}else if(v[q]==0){
				ans=max(ans,maxr);
				maxr=0;
				maxm=0;
			}else {
				if(maxr)maxr*=v[q];
				else maxr=v[q];
				if(maxm)maxm*=v[q];
				else maxm=v[q];
			}
		}
		cout<<"Case #"<<t++<<": The maximum product is "<<ans<<"."<<endl<<endl;
	}
}