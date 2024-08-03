// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int name2p(string s){
    if(s=="elder")return 1;
    if(s=="nursy")return 2;
    if(s=="kit")return 3;
    if(s=="warrior")return 4;
    if(s=="appentice")return 5;
    if(s=="medicent")return 6;
    if(s=="deputy")return 7;
    return 8;
}
struct C{
    string name;
    int p,y;
}cat[10010];
bool cmp(C a,C b){
    if(a.p==b.p){
        if(a.p==5){
            if(a.y==b.y)return a.name<b.name;
            return a.y<b.y;
        }else {
            if(a.y==b.y)return a.name<b.name;
            return a.y>b.y;
        }
    }
    return a.p<b.p;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    string t;
    while(cin>>n>>m){
        for(int q=0;q<n;q++){
            cin>>cat[q].name>>t>>cat[q].y;
            cat[q].p=name2p(t);
        }
        sort(cat,cat+n,cmp);
        for(int q=0;q<min(m,n);q++){
            cout<<cat[q].name<<endl;
        }
    }
}
