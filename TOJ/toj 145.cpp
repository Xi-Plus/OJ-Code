#include <iostream>
using namespace std;
int main(){
    int n,m,k,q,a,b,c,d;
    while(cin>>n>>m>>k>>q){
        int v[n+1][m+1];
        for(int e=0;e<=n;e++)for(int w=0;w<=m;w++)v[e][w]=0;
        while(k--){
            cin>>a>>b;
            v[a+1][b+1]++;
        }
        /*for(int e=0;e<=n;e++){
            for(int w=0;w<=m;w++)cout<<v[e][w]<<" ";
            cout<<endl;
        }*/
        for(int e=1;e<=n;e++)for(int w=1;w<=m;w++)v[e][w]=v[e][w-1]+v[e-1][w]-v[e-1][w-1]+v[e][w];
        /*for(int e=0;e<=n;e++){
            for(int w=0;w<=m;w++)cout<<v[e][w]<<" ";
            cout<<endl;
        }*/
        while(q--){
            cin>>a>>b>>c>>d;
            cout<<v[c+1][d+1]-v[a][d+1]-v[c+1][b]+v[a][b]<<endl;
        }
    }
}