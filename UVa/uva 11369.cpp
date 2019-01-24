#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int v[20005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		for(int q=0; q<n; q++) {
			cin>>v[q];
		}
		sort(v, v+n);
		long long sum=0;
		for(int q=n-3; q>=0; q-=3) {
			sum += v[q];
		}
		cout<<sum<<endl;
	}
}
