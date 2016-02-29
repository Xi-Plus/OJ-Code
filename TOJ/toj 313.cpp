// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int v[10010][10010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,r,l,x,m;
    cin>>t;
    while(t--){
        cin>>r>>l>>x>>m;
        for(int q=1;q<=r;q++)v[1][q]=1;
        for(int q=2;q<=l;q+=2){
            v[q][r]=v[q-1][r];
            for(int w=r-1;w>=1;w--){
                v[q][w]=(v[q][w+1]+v[q-1][w])%m;
            }
            v[q+1][1]=v[q][1];
            for(int w=2;w<=r;w++){
                v[q+1][w]=(v[q+1][w-1]+v[q][w])%m;
            }
        }
        cout<<v[l][x]<<endl;
    }
}