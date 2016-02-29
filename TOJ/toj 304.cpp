// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int n,a;
    char c;
    cin>>n;
    c=getchar();
    c=getchar();
    n--;
    cin>>a;
    cout<<a;
    while(n--){
        cin>>a;
        cout<<c<<a;
    }
    cout<<endl;
}