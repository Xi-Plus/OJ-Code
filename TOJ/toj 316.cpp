#include <bits/stdc++.h>
#define endl '\n'
#define double long double
using namespace std;
double eps=pow(2,0.0001);
bool check(double a,double b){
    a=abs(a);
    b=abs(b);
    if(max(a,b)<=min(a,b)*eps)return true;
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    int a,b;
    double ta,tb,na,nb;
    while(t--){
        na=nb=1;
        cin>>a;
        while(a--){
            cin>>ta;
            na*=ta;
        }
        cin>>b;
        while(b--){
            cin>>tb;
            nb*=tb;
        }
        if(check(na,nb))cout<<0<<endl;
        else if(na<nb)cout<<-1<<endl;
        else cout<<1<<endl;
    }
}