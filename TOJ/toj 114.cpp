#include <iostream>
using namespace std;
int main(){
    int a[5][6];
    for(int q=0;q<5;q++)for(int w=0;w<6;w++)cin>>a[q][w];
    bool x=0;
    for(int q=0;q<=4;q++)for(int w=0;w<=3;w++)if(a[q][w]==a[q][w+1]&&a[q][w+1]==a[q][w+2]){
        x=1;
        break;
    }
    for(int q=0;q<=2;q++)for(int w=0;w<=5;w++)if(a[q][w]==a[q+1][w]&&a[q+1][w]==a[q+2][w]){
        x=1;
        break;
    }
    if(x)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}