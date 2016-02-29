#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct V{
    int a;
    int b;
    bool x;
};
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    V v1[m],v2[m];
    for(int q=0;q<m;q++){
        scanf("%d%d",&v1[q].a,&v1[q].b);
        v1[q].x=0;
        v2[q].a=v1[q].a;
        v2[q].b=v1[q].b;
        v2[q].x=0;
    }
    int tree[n];
    memset(tree,-1,sizeof tree);
    tree[v1[0].a]=0;
    tree[v1[0].b]=1;
    v1[0].x=1;
    bool empty=1;
    while(empty){
        empty=0;
        for(int q=0;q<m;q++){
            if(v1[q].x==0&&tree[v1[q].a]!=-1){
                tree[v1[q].b]=tree[v1[q].a]+1;
                v1[q].x=1;
                empty=1;
            }
            else if(v1[q].x==0&&tree[v1[q].b]!=-1){
                tree[v1[q].a]=tree[v1[q].b]+1;
                v1[q].x=1;
                empty=1;
            }
        }
    }
    int maxd=-1,maxn=-1;
    for(int q=0;q<n;q++){
        if(tree[q]>maxd){
            maxd=tree[q];
            maxn=q;
        }
    }
    memset(tree,-1,sizeof tree);
    tree[maxn]=0;
    empty=1;
    while(empty){
        empty=0;
        for(int q=0;q<m;q++){
            if(v2[q].x==0&&tree[v2[q].a]!=-1){
                tree[v2[q].b]=tree[v2[q].a]+1;
                v2[q].x=1;
                empty=1;
            }
            else if(v2[q].x==0&&tree[v2[q].b]!=-1){
                tree[v2[q].a]=tree[v2[q].b]+1;
                v2[q].x=1;
                empty=1;
            }
        }
    }
    maxd=-1,maxn=-1;
    for(int q=0;q<n;q++){
        if(tree[q]>maxd){
            maxd=tree[q];
            maxn=q;
        }
    }
    printf("%d\n",maxd);
}