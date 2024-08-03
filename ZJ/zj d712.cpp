// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int count(int n){
	if(n==1) return 0;
	if(n&1) return count(n*3+1)+1;
	return count(n/2)+1;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int a,b;
	while(cin>>a>>b){
		cout<<a<<" "<<b<<" ";
		if(a>b)swap(a,b);
		int ans=0;
		for(int q=a;q<=b;q++){
			ans=max(count(q)+1,ans);
		}
		cout<<ans<<endl;
	}
}
