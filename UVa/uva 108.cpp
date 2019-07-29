#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int v[105][105], v2[105];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int q=1; q<=n; q++) {
		for(int w=1; w<=n; w++) {
			cin>>v[q][w];
		}
	}
	for(int w=1; w<=n; w++) {
		v[0][w]=0; 
		for(int q=2; q<=n; q++) {
			v[q][w] += v[q-1][w];
		}
	}
	int ans = -1e9;
	for(int q1=1; q1<=n; q1++) {
		for(int q2=q1; q2<=n; q2++) {
			v2[0]=0;
			for(int w=1; w<=n; w++) {
				v2[w] = v[q2][w]-v[q1-1][w];
			}
			for(int q=1; q<=n; q++) {
				if(v2[q-1]>0){
					v2[q]+=v2[q-1];
				}
			}
			for(int q=1; q<=n; q++) {
				ans=max(ans, v2[q]);
			}
		}
	}
	cout<<ans<<endl;
}
