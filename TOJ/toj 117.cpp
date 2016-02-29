#include <iostream>
using namespace std;
int main(){
    int t;
    int a,max=0;
    cin>>t;
    while(t--){
        cin>>a;
        if(a>max)max=a;
    }
    cout<<max<<endl;
}