// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n;
    k=1;
//    cin>>k;
    int old[n+1],v[n+1+k];
    for(int q=1;q<=n;q++){
        cin>>v[q];
        old[q]=v[q];
    }
    v[0]=0;
    int ans=v[1];
    for(int q=1;q<=n;q++){
        v[q]+=v[q-1];
        if(old[q]<0&&v[q]<0){
            v[q+k]-=max(old[q],v[q]);
        }
//        cout<<v[q]<<endl;
        if(v[q]>ans)ans=v[q];
    }
    cout<<ans<<endl;
}
