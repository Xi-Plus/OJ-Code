#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long calc(long long b, long long p, long long m) {
	if(p == 0) return 1;
	long long tmp = calc(b, p/2, m)%m;
	if(p&1) return tmp*tmp*b%m;
	return tmp*tmp%m;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long b, p, m;
	while(cin>>b>>p>>m) {
		cout<<calc(b%m, p, m)<<endl;
	}
}
