#include <iostream>
using namespace std;
int main(){
    int a;
    while(cin>>a){
        switch(a){
            case 3:
            case 4:
            case 5:
                cout<<"Spring!"<<endl;
                break;
            case 6:
            case 7:
            case 8:
                cout<<"Summer!"<<endl;
                break;
            case 9:
            case 10:
            case 11:
                cout<<"Autumn!"<<endl;
                break;
            default:
                cout<<"Winter!"<<endl;
                break;
        }
    }
}