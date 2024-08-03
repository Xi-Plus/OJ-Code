// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef unsigned long long ULL;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	unsigned long long v[3],m,n;
	while(cin>>v[0]>>v[1]>>v[2]){
		sort(v,v+3);
		m=sqrt(v[1]-v[0]);
		n=sqrt(v[2]-v[0]);
		cout<<m*m+m*n+n*n<<endl;
	}
}
