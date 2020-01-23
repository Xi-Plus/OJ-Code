#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n, k;
	cin>>n>>k;
	char format[100];
	sprintf(format, "%%.%df%%%%\n", k);
	int v[n];
	for(int q=0; q<n; q++){
		cin>>v[q];
	}
	sort(v, v+n);
	int m;
	cin>>m;
	int p, q;
	while(m--){
		cin>>p>>q;
		if(p>q){
			swap(p, q);
		}
		int cnt = upper_bound(v, v+n, q) - lower_bound(v, v+n, p);
		printf(format, 100.0*cnt/n);
	}
}

