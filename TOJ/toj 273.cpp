//#include <bits/stdc++.h>
#include <iostream>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int q=0;q<n;q++){
            for(int w=0;w<n-q-1;w++){
                cout<<" ";
            }
            for(int w=0;w<q+1;w++){
                cout<<(char)('A'+n-w-1);
            }
            for(int w=q-1;w>=0;w--){
                cout<<(char)('A'+n-w-1);
            }
            cout<<endl;
        }
        for(int q=0;q<n-1;q++){
            for(int w=0;w<q+1;w++){
                cout<<" ";
            }
            for(int w=0;w<n-q-1;w++){
                cout<<(char)('A'+n-w-1);
            }
            for(int w=n-q-3;w>=0;w--){
                cout<<(char)('A'+n-w-1);
            }
            cout<<endl;
        }
    }
    return 0;
}