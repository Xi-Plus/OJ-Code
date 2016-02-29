#include <iostream>
using namespace std;
int main(){
    string s[11];
    for(int q=1;q<=10;q++)s[q]="EMPTY";
    int n;
    cin>>n;
    while(n--){
        string i;
        int k;
        cin>>i>>k;
        s[k]=i;
    }
    for(int q=1;q<=10;q++)cout<<s[q]<<endl;
}