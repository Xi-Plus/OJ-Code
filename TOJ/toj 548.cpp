#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	long long n, k, v;
	cin>>n>>k;
	for(int q=0;q<n; q++){
		cin>>v;
		v=(v+10)*2;
		v=v*v;
		if(v>k) {
			cout<<"BURST!!!"<<endl;
			break;
		}
		cout<<v<<endl;
	}
}

