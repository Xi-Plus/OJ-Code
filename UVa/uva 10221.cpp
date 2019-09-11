#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long s, a;
	string mode;
	cout<<fixed<<setprecision(6);
	while(cin>>s>>a>>mode){
		if(mode=="deg"){
			a%=360;
			if(a>=180) {
				a=360-a;
			}
			cout<<2*(6440+s)*atan(1)*4*a/360<<" "
				<<sqrt(pow(6440+s, 2)*2-2*pow(6440+s, 2)*cos(1.0*a/180*atan(1)*4))
				<<endl;
		}else{
			a%=360*60;
			if(a>=180*60) {
				a=360*60-a;
			}
			cout<<2*(6440+s)*atan(1)*4*a/60/360<<" "
				<<sqrt(pow(6440+s, 2)*2-2*pow(6440+s, 2)*cos(1.0*a/60/180*atan(1)*4))
				<<endl;
		}
	}
}
