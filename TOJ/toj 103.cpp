#include <iostream>
using namespace std;
int main(){
    string a,b;
    int c,d;
    cin>>a>>c>>b>>d;
    if(a==b&&c==d)cout<<"GOOD"<<endl;
    else if(a!=b&&c!=d)cout<<"OTZ"<<endl;
    else cout<<"=~="<<endl;
}