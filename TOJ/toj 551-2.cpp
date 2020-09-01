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
		while(true){
			while(n%6==0)n/=6;
			if(n==1)break;
			if(k==0)break;
			k--;
			n*=2;
		}
		if(n==1){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
}

