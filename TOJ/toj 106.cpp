#include <iostream>
using namespace std;
int main(){
    long long int a=2;
    while(true){
        a=a*2+1;
        if(a%71==0)break;
    }
    if(a%3==0)cout<<"right"<<endl;
    else cout<<"left"<<endl;
}