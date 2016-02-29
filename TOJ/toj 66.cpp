#include<iostream>
#include<sstream>
#include<cstdio>
using namespace std;
int main(){
    string s;
    char p;
    while(getline(cin,s)){
        long long int ans=0;
        string a;
        istringstream t(s);
        while(t>>a){
            for(int i=0;i<a.size();i++)if(a[i]=='/')goto E;
            int b;
            sscanf(a.c_str(),"%d",&b);
            ans+=b;
            E:
            ans%=1000000007;
        }
        cout<<ans%1000000007<<endl;
    }
}