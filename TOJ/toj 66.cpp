// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
    string s;
    while(getline(cin,s)){
        long long int ans=0;
        string a;
        stringstream t(s);
        while(t>>a){
			if(a.find("/")==string::npos){
				ans+=atoi(a.c_str());
				ans%=1000000007;
			}
        }
        cout<<ans<<endl;
    }
}