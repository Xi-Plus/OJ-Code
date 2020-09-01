#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n;
	string s;
	while(cin>>n) {
		long long a=INT_MAX, b=0, sz;
		cin.ignore();
		for(int q=0; q<n; q++){
			getline(cin, s);
			sz=s.size();
			a=min(a, sz);
			b=max(b,sz);
			cout<<sz<<endl;
		}
		cout<<a<<" "<<b<<" "<<__gcd(a, b)<<endl;
	}
}

