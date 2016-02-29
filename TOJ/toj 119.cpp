#include <cmath>
#include <iostream>
using namespace std;
int main(){
    int n,t,a,b,k;
    int v[200005];
    while(cin>>n){
        for(int q=1;q<=n;q++)cin>>v[q];
        cin>>t;
        bool x=1;
        for(int q=1;q<=t;q++){
            cin>>a>>b;
            if(abs(a-b)>8)x=0;
            if(x){
                k=v[a];
                v[a]=v[b];
                v[b]=k;
            }
        }
        if(x)cout<<"SORTED!"<<endl;
        else cout<<"I QUIT!"<<endl;
        cout<<v[1];
        for(int q=2;q<=n;q++)cout<<" "<<v[q];
        cout<<endl;
    }
}