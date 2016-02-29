#include <iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        int v[n];
        for(int q=n-1;q>=0;q--)cin>>v[q];
        int p=-1,ans=0;
        for(int q=0;q<n;q++){
            if(v[q]>p){
                p=v[q];
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}