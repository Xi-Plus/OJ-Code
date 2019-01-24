#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long v[14];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	v[0] = 1;
	for(int q=1; q<100; q++) {
		v[q] = v[q-1]*q;
	}
	int n;
	while(cin>>n) {
		if(n<0) {
			if(n&1) cout<<"Overflow!"<<endl;
			else cout<<"Underflow!"<<endl;
		} else {
			if(n>13) cout<<"Overflow!"<<endl;
			else if(v[n] < 10000) cout<<"Underflow!"<<endl;
			else cout<<v[n]<<endl;
		}
	}
}
