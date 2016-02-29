#include<iostream>
using namespace std;
int main()
{
    int a,b;
    while(cin>>a>>b){
        while((a%=b)&&(b%=a));
        cout<<a+b<<endl;
    }
    return 0;
}