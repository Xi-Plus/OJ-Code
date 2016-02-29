// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int v[500010][2];
int findleader(int a){
    if(v[a][0]==a)return v[a][0];
    return v[a][0]=findleader(v[a][0]);
}
bool setfriends(int a,int b){
    int A=findleader(a),B=findleader(b);
    if(v[A][0]==v[B][0])return false;
    if(v[A][1]==v[B][0])return true;
    if(v[A][1]==0&&v[B][1]==0){
        v[B][0]=A;
    }
    else if(v[A][1]==0&&v[B][1]!=0){
        v[A][0]=B;
    }
    else if(v[A][1]!=0&&v[B][1]==0){
        v[B][0]=A;
    }
    else {
        v[B][0]=A;
        v[v[B][1]][0]=v[A][1];
    }
    return false;
}
bool setenemies(int a,int b){
    int A=findleader(a),B=findleader(b);
    if(v[A][0]==v[B][0])return true;
    if(v[A][1]==0&&v[B][1]==0){
        v[A][1]=B;
        v[B][1]=A;
    }
    else if(v[A][1]==0&&v[B][1]!=0){
        v[A][0]=v[B][1];
    }
    else if(v[A][1]!=0&&v[B][1]==0){
        v[B][0]=v[A][1];
    }
    else {
        v[B][0]=v[A][1];
        v[v[B][1]][0]=A;
    }
    return false;
}
bool isfriends(int a,int b){
    int A=findleader(a),B=findleader(b);
    return A==B;
}
bool isenemies(int a,int b){
    int A=findleader(a),B=findleader(b);
    return v[A][1]==v[B][0];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(v,0,sizeof(v));
    int n;cin>>n;
    char c;
    string s;
    int a,b;
    for(int q=0;q<n;q++){
        cin>>c>>s>>s;
        if(c=='y'){
            cin>>c>>s>>a>>b;
            if(v[a][0]==0)v[a][0]=a;
            if(v[b][0]==0)v[b][0]=b;
            if(c=='f'){
                if(setfriends(a,b)){
                    cout<<"angry"<<endl;
                }
            }else {
                if(setenemies(a,b)){
                    cout<<"angry"<<endl;
                }
            }
        }else{
            cin>>c>>s>>a>>b;
            if(v[a][0]==0)v[a][0]=a;
            if(v[b][0]==0)v[b][0]=b;
            if(c=='f'){
                if(isfriends(a,b)){
                    cout<<"yeap"<<endl;
                }else {
                    cout<<"nope"<<endl;
                }
            }else {
                if(isenemies(a,b)){
                    cout<<"yeap"<<endl;
                }else {
                    cout<<"nope"<<endl;
                }
            }
        }
    } 
}