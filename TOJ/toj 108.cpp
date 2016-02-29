#include <iostream>
using namespace std;
int main(){
    int a,b,c,d,e;
    cin>>a>>b>>c;
    a-=c;
    while(b--){
        cin>>d>>e;
        a+=d*e;
    }
    cout<<a/4<<endl;
}