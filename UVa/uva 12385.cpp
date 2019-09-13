#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n, k, l, ans, last[100005];
	cin>>t;
	while(t--){
		cin>>n;
		memset(last, 0, sizeof(last));
		l=0;
		ans=0;
		for(int q=1; q<=n; q++){
			cin>>k;
			if(last[k]>=l&&last[k]!=0){
				ans++;
				l=q;
			}
			last[k]=q;
		}
		cout<<ans<<endl;
	}
}
