#include<cstdio>
//#include<iostream>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    int a0,a1,m,n,k;
    while(t--){
        scanf("%d%d%d%d",&a0,&a1,&m,&n);
        int v[n+1];
        v[0]=a0;
        v[1]=a1;
        for(int q=2;q<=n;q++){
//            cout<<q/2<<" "<<q/3<<" "<<q/4<<" "<<q/5<<" ";
            v[q]=((v[q/2]+v[q/3]+v[q/4])*v[q/5])%m;
//            printf("%lld\n",v[q]);
//            for(int w=0;w<=q;w++)cout<<v[w]<<" ";
//            cout<<endl;
        }
        printf("%lld\n",v[n]);
    }
    return 0;
}