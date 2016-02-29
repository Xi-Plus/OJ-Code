#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        long long int a,b,c,d=0,e=0,f=0;
        cin>>a>>b>>c;
        if(a>=b&&a>=c){
        d=a;
            if(b>=c){
                e=b;
                f=c;
            }
            else{
                e=c;
                f=b; 
            }
        }
        
        else if(b>=a&&b>=c){
            d=b;
            if(a>c){
                e=a;
                f=c;
            }
            else{
                e=c;
                f=a;  
            }
        }
        
        else {
        d=c;
            if(a>b){
                e=a;
                f=b;
            }
            else{
                e=b;
                f=a;  
            }
        }
        if(d>=e+f)cout<<"illegal triangle"<<endl;
        else if(d*d<e*e+f*f)cout<<"obtuse triangle"<<endl;
        else if(d*d==e*e+f*f)cout<<"right triangle"<<endl;
        else if(d*d>e*e+f*f)cout<<"acute triangle"<<endl;
    }
}