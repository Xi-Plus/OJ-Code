#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, m, n, k, x, y;
	char a[105][105];
	cin>>t;
	while(t--){
		cin>>m>>n>>k;
		memset(a, ' ', sizeof(a));
		for(int q=1; q<=m; q++){
			for(int w=1; w<=n; w++){
				cin>>a[q][w];
			}
		}
		cout<<m<<" "<<n<<" "<<k<<endl;
		while(k--){
			cin>>x>>y;
			int ans=1;
			bool ok=true;
			x++;
			y++;
			while(true){
				for(int q=-ans; q<=ans; q++){
					if(a[x-ans][y+q]!=a[x][y]){
						ok=false;
						break;
					}
					if(a[x+ans][y+q]!=a[x][y]){
						ok=false;
						break;
					}
					if(a[x+q][y-ans]!=a[x][y]){
						ok=false;
						break;
					}
					if(a[x+q][y+ans]!=a[x][y]){
						ok=false;
						break;
					}
				}
				if(!ok){
					break;
				}
				ans++;
			}
			cout<<ans*2-1<<endl;
		}
	}
}
