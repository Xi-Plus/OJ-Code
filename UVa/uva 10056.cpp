#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int s, n, i;
	double p;
	cin>>s;
	cout<<fixed<<setprecision(4);
	while(s--){
		cin>>n>>p>>i;
		double ans=0;
		for(int q=0; q<100; q++){
			ans+=p*pow(1-p, i-1+n*q);
		}
		cout<<ans<<endl;
	}
}
