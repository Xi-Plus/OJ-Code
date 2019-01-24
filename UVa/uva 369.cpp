#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n, m, mm;
	while(cin>>n>>m, n) {
		mm = m;
		if(m*2 > n) m = n-m;
		long long ans = 1;
		for(int q=1; q<=m; q++) {
			ans *= n-q+1;
			ans /= q;
		}
		cout<<n<<" things taken "<<mm<<" at a time is "<<ans<<" exactly."<<endl;
	}
}
