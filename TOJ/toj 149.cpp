#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
struct V{
    int b;
//    int s;
    int g;
    //bool x;
};
int sortg(V a,V b)
{
    return a.g>b.g;
}
/*int sortb(V a,V b)
{
    return a.b<b.b;
}*/
int main(){
    int n;
    long long int m;
    scanf("%d%lld",&n,&m);
    vector<V> v;
    V temp;
    for(int q=0;q<n;q++){
        scanf("%d%d",&temp.b,&temp.g);
        temp.g-=temp.b;
        v.push_back(temp);
        /*if(v[q].g<=0)v[q].x=1;
        else v[q].x=0;*/
    }
    sort(v.begin(),v.end(),sortg);
    /*int start=0,end=-1,last=v[0].g;
    for(int q=0;q<n;q++){
        if(v[q].g!=last){
            end=q;
            sort(v+start,v+end,sortb);
            start=q;
            last=v[q].g;
        }
    }
    end=n;
    sort(v+start,v+end,sortb);*/
    S:
        bool x=1;
        for(int q=0;q<v.size();q++){
            if(/*v[q].x==0&&*/v[q].b<=m){
                m+=v[q].g;
//                v[q].x=1;
                x=0;
                v.erase(v.begin()+q);
//                printf("%d %d %d %d\n",v[q].b,v[q].s,v[q].g,m);
                goto S;
            }
        }
    printf("%lld\n",m);
}