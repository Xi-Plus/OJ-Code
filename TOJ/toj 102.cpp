#include <iomanip>
#include <iostream>
using namespace std;
int main(){
    double a,b;
    char c;
    cin>>a>>c>>b;
    cout<<fixed<<setprecision(4);
    switch(c){
        case '+':
            cout<<a<<" + "<<b<<" = "<<a+b<<endl;
            break;
        case '-':
            cout<<a<<" - "<<b<<" = "<<a-b<<endl;
            break;
        case '*':
            cout<<a<<" * "<<b<<" = "<<a*b<<endl;
            break;
        case '/':
            if(b==0)cout<<"ERROR"<<endl;
            else cout<<a<<" / "<<b<<" = "<<a/b<<endl;
            break;
    }
}