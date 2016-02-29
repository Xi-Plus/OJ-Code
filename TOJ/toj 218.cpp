#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
bool bp[1000002]={false};
int p[100000];
int main(){
    int k=2;
    bp[2]=false;
    bp[3]=false;
    p[1]=2;
    p[2]=3;
    int l;
    for(int q=4;q<1000000;q++){
        l=sqrt(q);
        for(int w=1;w<=k&&p[w]<=l;w++){
            if(q%p[w]==0){
                bp[q]=true;
                break;
            }
        }
        if(bp[q]==false){
            p[++k]=q;
        }
    }
    long long int a,b;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld",&a,&b);
        a=a*b;
        int now=1;
        long long int ans=1;
        while(a!=1){
            int z=0;
            while(a%p[now]==0){
                z++;
                a/=p[now];
            }
            ans*=(z+1);
            now++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}