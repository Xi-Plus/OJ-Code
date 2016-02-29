#include <iostream>
using namespace std;
int main(){
    long long int a=30;
    for(int q=1;q<=30;q++){
        a+=(q+q*q*(q+1)/2);
    }
    cout<<a<<endl;
}