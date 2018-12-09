#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	int v[n];
	for(int q=0; q<n; q++) {
		cin>>v[q];
	}
	int ans=0;
	for(int q=1; q<n-1; q++) {
		if(v[q]>v[q-1] && v[q]>v[q+1]) {
			ans++;
		} else if(v[q]<v[q-1] && v[q]<v[q+1]) {
			ans++;
		}
	}
	cout<<ans<<endl;
}
