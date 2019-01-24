#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		if(n==1) {
			cout<<1<<endl;
			continue;
		}
		vector<int> v;
		for(int q=9; q>=2; q--) {
			while(n%q==0) {
				v.emplace_back(q);
				n/=q;
			}
		}
		if(n!=1) {
			cout<<-1<<endl;
		} else {
			reverse(v.begin(), v.end());
			for(auto i:v) {
				cout<<i;
			}
			cout<<endl;
		}
	}
}
