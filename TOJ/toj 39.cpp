#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
    string s;
    long long int n=1;
    while(cin>>s){
        if(s=="%"){
            cout<<n<<endl;
            n=1;
        }
        else {
            n*=atoi(s.c_str());
            n%=479001599;
        }
    }
}