// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	long long a,b;
	while(cin>>a>>b){
		cout<<a+b-__gcd(a,b)<<endl;
	}
}
