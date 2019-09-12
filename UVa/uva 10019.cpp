#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n, x, x2, ans;
	cin>>t;
	while(t--){
		cin>>n;
		x=n;
		ans=0;
		while(x){
			ans+=x%2;
			x/=2;
		}
		cout<<ans<<" ";
		ans=0;
		x=n;
		while(x){
			x2=x%10;
			while(x2){
				ans+=x2%2;
				x2/=2;
			}
			x/=10;
		}
		cout<<ans<<endl;
	}
}
