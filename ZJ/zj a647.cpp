// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		long long a,b;
		cin>>a>>b;
		long long c=100000*(b-a)/a;
		bool m=(c>=10000||c<=-7000);
		if(c<0)cout<<"-";
		c=abs(c);
		long long x=c/1000,y=c%1000/10+(c%10>=5);
		if(y>=100){
			x++;
			y-=100;
		}
		cout<<x<<"."<<(y<10?"0":"")<<y<<"% ";
		if(m)cout<<"dispose"<<endl;
		else cout<<"keep"<<endl;
	}
}
