// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
    string s;
    while(getline(cin,s)){
        long long ansa=1,ansb=1;
        string a;
        stringstream t(s);
        while(t>>a){
			if(a.find("/")==string::npos){
				ansa*=atoi(a.c_str());
			}else {
				stringstream t2(a);
				int na,nb;
				char c;
				t2>>na>>c>>nb;
				ansa*=na;
				ansb*=nb;
			}
        }
        long long gcd=__gcd(ansa,ansb);
        ansa/=gcd;
        ansb/=gcd;
        if(ansb==1){
			cout<<ansa<<endl;
        }else {
        	cout<<ansa<<"/"<<ansb<<endl;
        }
    }
}