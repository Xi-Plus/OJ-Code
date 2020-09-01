#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n;
	string a, b;
	cin>>n>>a>>b;
	int ans=0;
	for(int q=0; q<n; q++){
		ans+=a[q]!=b[q];
	}
	cout<<max(ans-2, 0)<<endl;
}

