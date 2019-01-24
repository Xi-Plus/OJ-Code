#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int v[1000005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while(cin>>n) {
		for(int q=0; q<n; q++) {
			cin>>v[q];
		}
		sort(v, v+n);
		if(n&1 || v[n/2-1] == v[n/2]) {
			cout<<v[(n-1)/2]<<" "
				<<upper_bound(v, v+n, v[(n-1)/2])-lower_bound(v, v+n, v[(n-1)/2])<<" "
				<<1<<endl;
		} else {
			int highidx = upper_bound(v, v+n, v[n/2])-v-1;
			int lowidx = lower_bound(v, v+n, v[n/2-1])-v;
			cout<<v[n/2-1]<<" "
				<<highidx-lowidx+1<<" "
				<<v[highidx]-v[lowidx]+1<<endl;
		}
	}
}
