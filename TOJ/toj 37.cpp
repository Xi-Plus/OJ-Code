// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
    string s;
    while(getline(cin,s)){
        int ans=0;
        stringstream ss;
        ss<<s;
        int t;
        while(ss>>t){
			ans++;
        }
        cout<<ans<<endl;
    }
}