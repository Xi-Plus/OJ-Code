#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long x, n, a, t;
	string s;
	while(cin>>x){
		cin.ignore();
		getline(cin, s);
		stringstream ss(s);
		vector<long long> a;
		n=-1;
		while(ss>>t){
			a.push_back(t);
			n++;
		}
		for(int q=0; q<n; q++){
			a[q]*=n-q;
		}
		long long ans=0;
		for(int q=0; q<n; q++){
			ans*=x;
			ans+=a[q];
		}
		cout<<ans<<endl;
	}
}
