#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n, n3, sum;
	cin>>t;
	while(t--){
		cin>>n;
		int ans=n;
		for(int n2=n-1; n2>=max(n-45, 0); n2--){
			sum=n3=n2;
			while(n3){
				sum+=n3%10;
				n3/=10;
			}
			if(sum==n){
				ans=n2;
			}
		}
		if(ans==n){
			cout<<0<<endl;
		}else{
			cout<<ans<<endl;
		}
	}
}
