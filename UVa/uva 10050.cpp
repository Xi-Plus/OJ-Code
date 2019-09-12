#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, day, p, pa[105];
	cin>>t;
	while(t--){
		cin>>day;
		cin>>p;
		for(int q=0; q<p; q++){
			cin>>pa[q];
		}
		int ans=0;
		for(int d=1; d<=day; d++){
			if(d%7==6||d%7==0){
				continue;
			}
			for(int q=0; q<p; q++){
				if(d%pa[q]==0){
					ans++;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
}
