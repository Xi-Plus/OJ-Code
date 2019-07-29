#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int v[10005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, ans;
	while(cin>>n, n) {
		v[0]=0;
		for(int q=1; q<=n; q++) {
			cin>>v[q];
			if(v[q-1]>0){
				v[q]+=v[q-1];
			}
		}
		ans=0;
		for(int q=1; q<=n; q++) {
			ans=max(ans, v[q]);
		}
		if (ans <= 0) {
			cout<<"Losing streak."<<endl; 
		} else {
			cout<<"The maximum winning streak is "<<ans<<"."<<endl;
		}
	}
}
