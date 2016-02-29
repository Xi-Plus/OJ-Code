#include <iostream>
using namespace std;
int main(){
    int n,z[1001];
    cin>>n;
    int a,b;
    while(n--){
        cin>>a>>b;
        z[a]=b;
    }
    cin>>n;
    while(n--){
        cin>>a>>b;
        int m=b-z[a]*a;
        if(m)cout<<m<<endl;
        else cout<<"The shopkeeper is honest."<<endl;
    }
}