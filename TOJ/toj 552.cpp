#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int k, n;
	cin>>k>>n;
	long long v[70]={0, 1};
	for(int q=1; q<=n; q++){
		for(int w=q; w>=1; w--){
			v[w]+=v[w-1];
		}
		if(q>=k+1){
			for(int w=0; w<n-q; w++){
				cout<<" ";
			}
			for(int w=1; w<=q; w++){
				cout<<v[w]<<" ";
			}
			cout<<endl;
		}
	}
}

