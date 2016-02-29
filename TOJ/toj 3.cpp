#include <iostream>
using namespace std;
int main(){
    long long int a,b;
    int n;
    cin>>n;
    while(n--){
        cin>>a>>b;
        while((a%=b)&&(b%=a));
        cout<<a+b<<endl;
    }
}