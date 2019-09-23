#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	map<string, int> point;
	int m, n, p;
	cin>>m>>n;
	string s;
	while(m--){
		cin>>s>>p;
		point[s]=p;
	}
	while(n--){
		int ans=0;
		while(cin>>s, s!="."){
			ans+=point[s];
		}
		cout<<ans<<endl;
	}
}
