#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, n2, m;
	while(cin>>n>>m){
		stringstream ans;
		bool fail=false;
		ans<<n;
		if(m<=1||n<=1){
			fail=true;
		}else{
			while(n>1){
				if(n%m!=0){
					fail=true;
					break;
				}
				n/=m;
				ans<<" "<<n;
			}
		}
		if(fail){
			cout<<"Boring!"<<endl;
		}else{
			cout<<ans.str()<<endl;
		}
	}
}
