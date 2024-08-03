// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	cout<<fixed<<setprecision(2);
	string s;
	while(cin>>s){
		stringstream ss(s);
		long long n,d;
		char c;
		ss>>n>>c>>d;
		n=n*100+d;
		if(n<=100*100)n=n*9+8*1000;
		else if(n<=500*100)n*=8;
		else n*=6;
		long long a=n/1000,b=n%1000/10;
		cout<<"$"<<a<<"."<<(b<10?"0":"")<<b<<endl;
	}
}
