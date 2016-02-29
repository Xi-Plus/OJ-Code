#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double a,b,c,d;
    while(cin>>a>>b>>c>>d){
        if(fabs(a*d-b*c)<0.00001)cout<<0<<endl;
        else cout<<1<<endl;
    }
}