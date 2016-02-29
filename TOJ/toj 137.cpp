#include<cstdio>
using namespace std;
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        if(n==0)break;
        if(n==1&m==1)printf("1 1 Multiple\n");
        else if(n==1)printf("1 %d Impossible\n",m);
        else if((m-1)%(n-1)!=0)printf("%d %d Impossible\n",n,m);
        else printf("%d %d %d\n",n,m,((m-1)/(n-1)*n+1));
    }
    return 0;
}