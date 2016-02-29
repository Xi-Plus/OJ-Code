#include <iostream>
using namespace std;
int main(){
    char c;
    cin>>c;
    if(c=='A')cout<<"@"<<endl;
    else cout<<(char)(c-1)<<endl;
}