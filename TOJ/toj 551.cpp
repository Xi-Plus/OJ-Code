#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	long long t, n, k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		int c2=0, c3=0;
		while(n%2==0){
			c2++;
			n/=2;
		}
		while(n%3==0){
			c3++;
			n/=3;
		}
		if(n==1){
			if(c3>=c2&&c3<=c2+k){
				cout<<"Yes"<<endl;
			}else{
				cout<<"No"<<endl;
			}
		}else{
			cout<<"No"<<endl;
		}
	}
}

