#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    int a,b;
    while(n--){
        cin>>s;
        a=(s[0]-'A')*26*26+(s[1]-'A')*26+(s[2]-'A');
        b=(s[4]-'0')*1000+(s[5]-'0')*100+(s[6]-'0')*10+(s[7]-'0');
        if(abs(a-b)<=100)cout<<"nice"<<endl;
        else cout<<"not nice"<<endl;
    }
    return 0;
}