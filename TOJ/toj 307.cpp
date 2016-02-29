// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    string a,b,ans=" ";
    getline(cin,a);
    getline(cin,b);
    int v[256]={0};
    int sz=b.size();
    for(int q=0;q<sz;q++){
        v[b[q]]++;
    }
    sz=a.size();
    for(int q=0;q<sz;q++){
        if(a[q]==' '){
            ans+=" ";
        }
        else if(v[a[q]]){
            ans+=a[q];
            v[a[q]]--;
        }
        else break;
    }
    if(ans[ans.size()-1]==' ')ans.erase(ans.size()-1,1);
    ans.erase(0,1);
    cout<<ans<<endl;
}