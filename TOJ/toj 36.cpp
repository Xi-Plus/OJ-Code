#include <cstdio> 
using namespace std;
int main(){
    long long int b;
    int a,c,v[100000],max;
    while(~scanf("%d%lld%d",&a,&b,&c)){
        a%=c;
        v[1]=a;
        for(max=1;;max++){
            v[max+1]=v[max]*a%c;
            if(v[max+1]==a)break;
        }
        printf("%d\n",v[(b%max==0?max:b%max)]%c);
    }
}