#include <iostream>
using namespace std;
int main(){
    int n,a,b,k=0;
    cin>>n;
    while(n--){
        cin>>a>>b;
        if(a==0&&b==2)k++;
        else if(a==2&&b==5)k++;
        else if(a==5&&b==0)k++;
        else if(a==2&&b==0)k--;
        else if(a==5&&b==2)k--;
        else if(a==0&&b==5)k--;
    }
    if(k>0)cout<<"The prince wins."<<endl;
    else if(k==0)cout<<"The referee wins."<<endl;
    else cout<<"The princess wins."<<endl;
}