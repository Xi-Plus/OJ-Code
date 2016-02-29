#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long a,b,m;
__int128 p(__int128 a,__int128 b){
    if(b==0) return 1;
    if(b%2) return p(a,b/2)%m*p(a,b/2)%m*a%m;
    return p(a,b/2)%m*p(a,b/2)%m;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>a>>b>>m;
        a%=m;
        long long ans=p(a,b)%m;
        cout<<ans<<endl;
    }
}