#include<cstdio>
using namespace std;
int main()
{
    int t,ans;
    scanf("%d",&t);
    int a,b,c,n;
    while(t--){
        scanf("%d%d%d%d",&n,&a,&b,&c);
        if(2*b>(a+c))
            printf("%d/1\n",n*b);
        else
        {
            ans=n*(a+c);
            if(ans%2==0)printf("%d/1\n",ans/2);
            else printf("%d/2\n",ans);
        }
    }
    return 0;
}