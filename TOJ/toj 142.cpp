#include <iostream>
using namespace std;
int main(){
    char v[3][3];
    while(cin>>v[0][0]>>v[0][1]>>v[0][2]){
        for(int q=1;q<=2;q++)for(int w=0;w<=2;w++)cin>>v[q][w];
        bool x=0;
        for(int q=0;q<=2;q++)for(int w=0;w<=2;w++)if(v[q][w]=='#')x=1;
        char c=0;
        int k=0;
        for(int q=0;q<=2;q++){
            for(int w=0;w<=2;w++)k+=v[q][w];
            if(k=='O'*3){
                c='A';
                goto E;
            }
        }
        for(int q=0;q<=2;q++){
            for(int w=0;w<=2;w++)k+=v[w][q];
            if(k=='O'*3){
                c='A';
                goto E;
            }
        }
        k=0;
        for(int q=0;q<=2;q++)k+=v[q][q];
        if(k=='O'*3){
            c='A';
            goto E;
        }
        k=0;
        for(int q=0;q<=2;q++)k+=v[q][2-q];
        if(k=='O'*3){
            c='A';
            goto E;
        }
        for(int q=0;q<=2;q++){
            for(int w=0;w<=2;w++)k+=v[q][w];
            if(k=='X'*3){
                c='B';
                goto E;
            }
        }
        for(int q=0;q<=2;q++){
            for(int w=0;w<=2;w++)k+=v[w][q];
            if(k=='X'*3){
                c='B';
                goto E;
            }
        }
        k=0;
        for(int q=0;q<=2;q++)k+=v[q][q];
        if(k=='X'*3){
            c='B';
            goto E;
        }
        k=0;
        for(int q=0;q<=2;q++)k+=v[q][2-q];
        if(k=='X'*3){
            c='B';
            goto E;
        }
        E:
        if(c!=0)cout<<c<<" wins."<<endl;
        else if(x)cout<<"Playing"<<endl;
        else cout<<"Draw"<<endl;
    }
}