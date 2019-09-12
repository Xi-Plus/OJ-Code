#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while(cin>>n){
		int ans=n;
		int n2=n+1;
		while(n2>=3){
			ans+=n2/3;
			n2=n2/3+n2%3;
		}
		int ans2=n;
		n2=n+2;
		while(n2>=3){
			ans2+=n2/3;
			n2=n2/3+n2%3;
		}
		if(n2==2){
			cout<<ans2<<endl;
		}else{
			cout<<ans<<endl;
		}
	}
}
