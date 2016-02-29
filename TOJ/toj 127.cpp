#include <iostream>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n>>s;
    for(int q=0;q<s.size();q++){
        if(s[q]-n<'A')cout<<(char)(s[q]-n+26);
        else cout<<(char)(s[q]-n);
    }
    cout<<endl;
}