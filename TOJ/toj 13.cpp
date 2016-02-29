// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long dp[100010];
int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int v,n,w,p;
    while(cin>>v>>n){
        memset(dp,0,sizeof(dp));
        while(n--){
            cin>>w>>p;
            for(int q=w;q<=v;q++){
//            for(int q=v;q-w>=0;q--){
                dp[q]=max(dp[q],dp[q-w]+p);
            }
        }
        cout<<dp[v]<<endl;
    }
}