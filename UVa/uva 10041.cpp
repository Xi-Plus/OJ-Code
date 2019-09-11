#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, r, arr[505];
	cin>>t;
	while(t--) {
		cin>>r;
		for(int q=0; q<r; q++){
			cin>>arr[q];
		}
		sort(arr, arr+r);
		int pick=arr[r/2];
		long long ans=0;
		for(int q=0; q<r; q++){
			ans+=abs(pick-arr[q]);
		}
		cout<<ans<<endl;
	}
}
