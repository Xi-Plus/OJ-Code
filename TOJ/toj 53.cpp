#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<sstream>
using namespace std;
int main(){
    string s;
    while(getline(cin,s)){
        int ans=0;
        int a;
        istringstream t(s);
        while(t>>a)ans+=a;
        cout<<ans<<endl;
    }
}