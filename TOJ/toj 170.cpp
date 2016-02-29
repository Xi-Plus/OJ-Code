#include <iostream>
using namespace std;
void echo_starts(int n,int space){
    for(int q=0;q<n;q++){
        for(int w=0;w<space;w++)cout<<" ";
        for(int w=0;w<n-q-1;w++)cout<<" ";
        for(int w=0;w<q*2+1;w++)cout<<"*";
        cout<<endl;
    }
}
int main(){
    int t,n;
    char c;
    cin>>t;
    while(t--){
        cin>>c>>n;
        switch(c){
            case 'A':
                echo_starts(n,0);
                break;
            case 'B':
                echo_starts(n,0);
                echo_starts(n,0);
                break;
            case 'C':
                for(int q=1;q<=n;q++)echo_starts(q,n-q);
                break;
            case 'D':
                echo_starts(n*10,0);
                break;
            case 'E':
                echo_starts(n,2);
                for(int q=1;q<=n*2+3;q++)cout<<"#";
                cout<<endl;
                break;
            case 'F': echo_starts(n*2,0);break;
            case 'G': echo_starts(n*3,0);break;
            case 'H': echo_starts(n*7,0);break;
            case 'I': echo_starts(n*4-1,0);break;
        }
        cout<<endl;
    }
}
