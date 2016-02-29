#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string s1,s2;
        cin>>s1>>s2;
        for(int q=0;q<n;q++){
            char a,b;
            if(s1[q]<='9'&&s1[q]>='0')a=s1[q]-'0';
            else a=s1[q]-'A'+10;
            if(s2[q]<='9'&&s2[q]>='0')b=s2[q]-'0';
            else b=s2[q]-'A'+10;
            char c=a xor b;
            if(c<10)c+='0';
            else c+='A'-10;
            cout<<c;
        }
        cout<<endl;
    }
}