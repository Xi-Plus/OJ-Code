#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void trans(long long n){
	if(n>=10000000){
		trans(n/10000000);
	}
	long long n2=n;
	if(n>=10000000){
		cout<<" kuti";
	}
	n2%=10000000;
	if(n2/100000){
		cout<<" "<<n2/100000<<" lakh";
		n2%=100000;
	}
	if(n2/1000){
		cout<<" "<<n2/1000<<" hajar";
		n2%=1000;
	}
	if(n2/100){
		cout<<" "<<n2/100<<" shata";
		n2%=100;
	}
	if(n2) {
		cout<<" "<<n2;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	int t=1;
	while(cin>>n){
		cout<<setw(4)<<t++<<".";
		trans(n);
		if(n==0) {
			cout<<" 0";
		}
		cout<<endl;
	}
}
