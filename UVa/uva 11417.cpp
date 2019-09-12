#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int arr[505][505];
	for(int q=1; q<505; q++){
		for(int w=q+1; w<505; w++){
			arr[q][w]=__gcd(q, w);
		}
	}
	int n;
	while(cin>>n, n){
		long long ans=0;
		for(int q=1; q<=n; q++){
			for(int w=q+1; w<=n; w++){
				ans+=arr[q][w];
			}
		}
		cout<<ans<<endl;
	}
}
