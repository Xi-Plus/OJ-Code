// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	long long v[n+1];v[0]=0;
	for(int q=1;q<=n;q++){
		cin>>v[q];
		v[q]^=v[q-1];
	}
	long long ans=0,ansl,ansr,t;
	for(int q=1;q<=n;q++){
		for(int w=q;w<=n;w++){
			t=v[w]^v[q-1];
			if(t>ans){
				ans=t;
				ansl=q;
				ansr=w;
			}
		}
	}
	cout<<ans<<" "<<ansl<<" "<<ansr<<endl;
}

