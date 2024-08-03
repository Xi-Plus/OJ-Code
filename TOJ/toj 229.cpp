// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int v1[100010],v2[100010],v3[200020],v4[200020];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T,N,K,x,y,d;
    cin>>T;
    while(T--){
        memset(v1,0,sizeof(v1));
        memset(v2,0,sizeof(v2));
        memset(v3,0,sizeof(v3));
        memset(v4,0,sizeof(v4));
        cin>>N>>K;
        int i=0;
        bool ans=false;
        while(i<N){
            i++;
            cin>>x>>y;
            v1[x]++;
            if(v1[x]>=K){
                ans=true;
                break;
            }
            v2[y]++;
            if(v2[y]>=K){
                ans=true;
                break;
            }
            v3[x+y]++;
            if(v3[x+y]>=K){
                ans=true;
                break;
            }
            v4[100010+x-y]++;
            if(v4[100010+x-y]>=K){
                ans=true;
                break;
            }
        }
        if(ans)cout<<i<<endl;
        else cout<<-1<<endl;
        while(i<N){
            i++;
            cin>>x>>y;
        }
    }
}
