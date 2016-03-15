// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef unsigned long long ULL;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	unsigned long long a,b,c;
	while(cin>>a>>b>>c){
		__int128 d=a,e=b,f=c;
		__int128 sum=d*d+e*e+f*f;
		__int128 l=0,r=9223372036854775807LL;
		r*=4;
		while(l<=r){
			__int128 m=(l+r)/2;
			if(m*m==sum){
				cout<<(ULL)m<<endl;
			}
			if(m*m<sum)l=m+1;
			else r=m-1;
		}
	}
}
