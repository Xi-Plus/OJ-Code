#include <cstdio>
#include <algorithm>
using namespace std;
struct V{
    int i;
    int m;
};
int cmp(V a,V b)
{
    return a.m>b.m;
}
int cmp2(V a,V b)
{
    return a.i<b.i;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        V v[n];
        for(int q=0;q<n;q++){
            v[q].i=q+1;
            scanf("%d",&v[q].m);
        }
        sort(v,v+n,cmp);
        int start=0,end=-1,last=v[0].m;
        for(int q=0;q<n;q++){
            if(v[q].m!=last){
                end=q;
//                cout<<" SORT:"<<start<<" to "<<end<<endl;
                sort(v+start,v+end,cmp2);
                start=q;
                last=v[q].m;
            }
        }
        end=n;
        sort(v+start,v+end,cmp2);
//        cout<<" SORT:"<<start<<" to "<<end<<endl;
//        for(int q=0;q<n;q++)cout<<v[q].i<<"\t";
//        cout<<endl;
//        for(int q=0;q<n;q++)cout<<v[q].m<<"\t";
//        cout<<endl;
        long long int sum=0;
        for(int q=0;q<n-1;q++){
            printf("%d ",v[q].i);
            sum+=v[q].m*(q+1);
        }
        printf("%d\n",v[n-1].i);
        sum+=v[n-1].m*(n);
        printf("%lld\n",sum);
    }
}