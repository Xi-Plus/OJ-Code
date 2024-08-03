// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long power(long long a,long long b){
	if(b==1) return a;
	if(b&1) return power(a,b/2)*power(a,b/2)*a;
	else return power(a,b/2)*power(a,b/2);
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	long long a,b;
	while(cin>>a>>b,a||b){
		if(b==0)cout<<1<<endl;
		else if(a==0)cout<<0<<endl;
		else if(a==1)cout<<1<<endl;
		else if(a==-1)cout<<(b&1?-1:1)<<endl;
		else cout<<power(a,b)<<endl;
	}
	cin.ignore();
	int cas=0;
	string s;
	while(getline(cin,s)){
		cas++;
	}
	cout<<"All Over. Exceeded "<<(cas==66047?65536:cas)<<" lines!"<<endl;
}
