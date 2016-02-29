#include <iostream>
using namespace std;
int main(){
    int n,a=0,b=0;
    cin>>n;
    char c;
    int q=1;
    for(;q<=n;q++){
        cin>>c;
        if(c=='P')break;
        a++;
    }
    q++;
    for(;q<=n;q++){
        cin>>c;
        b++;
    }
    cin>>c;
    int x;
    if(c=='L')x=-1;
    else x=1;
    for(int w=1;w<=a+x;w++)cout<<".";
    cout<<"P";
    for(int w=1;w<=b-x;w++)cout<<".";
    cout<<endl;
}