// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	long long n,a,b,c;
	cin>>n>>a>>b>>c;
	long long ans=0;
	if(n>=b&&b-c<a){
		ans+=(n-b)/(b-c)+1;
		n-=ans*(b-c);
	}
	ans+=n/a;
	cout<<ans<<endl;
}

