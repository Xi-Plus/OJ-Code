#include <iostream>
using namespace std;
int main(){
    int n,k;
    cin>>n;
    while(n--){
        cin>>k;
        for(int q=1;q<=k-3;q++){
            for(int w=1;w<=k-q;w++)cout<<" ";
            for(int w=1;w<=q*2-1;w++)cout<<"*";
            cout<<endl;
        }
        for(int q=1;q<=k*2-1;q++)cout<<"*";
        cout<<endl<<" ";
        for(int q=1;q<=k*2-3;q++)cout<<"*";
        cout<<endl;
        for(int q=1;q<=k*2-1;q++)cout<<"*";
        cout<<endl;
        for(int q=k-3;q>=1;q--){
            for(int w=1;w<=k-q;w++)cout<<" ";
            for(int w=1;w<=q*2-1;w++)cout<<"*";
            cout<<endl;
        }
    }
}