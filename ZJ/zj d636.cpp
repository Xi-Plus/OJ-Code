// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const long long m=10007;
long long power(long long a,long long b){
	if(b==1) return a;
	if(b&1){
		return power(a,b/2)%m*power(a,b/2)%m*a%m;
	}else {
		return power(a,b/2)%m*power(a,b/2)%m;
	}
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	long long a,b;
	while(cin>>a>>b){
		cout<<power(a,b)<<endl;
	}
}

