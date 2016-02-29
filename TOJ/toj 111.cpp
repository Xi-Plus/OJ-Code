#include <iostream>
using namespace std;
int main(){
    long long a=2;
    int b,c;
    cin>>b>>c;
    while(a%b){
        a=a*2+1;
    }
    if(a%c)cout<<"left"<<endl;
    else cout<<"right"<<endl;
}