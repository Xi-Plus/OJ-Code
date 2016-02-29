#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
struct sum{
    int id;
    long long int total;
};
bool sor(sum a, sum b){
    return a.total < b.total; 
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d,%d",&n,&m);
        int id[n];
        long long int v[n][3];
        int ia,ib,ic;
        int da,db,dc;
        for(int q=0;q<n;q++){
            scanf("%d,%d.%d,%d.%d,%d.%d",&id[q],&ia,&da,&ib,&db,&ic,&dc);
            v[q][0]=ia*1000+da;
            v[q][1]=ib*1000+db;
            v[q][2]=ic*1000+dc;
        }
        string str;
        cin>>str;
        int s=0,p=0,c=0,len=str.size();
        for(int w=0;w<len;w+=2){
            if(str[w]=='s')s++;
            else if(str[w]=='p')p++;
            else c++;
        }
        sum result[n];
        for(int q=0;q<n;q++){
            result[q].id=q+1;
            result[q].total=v[q][0]*s+v[q][1]*p+v[q][2]*c;
        }
        sort(result, result+n, sor);
        int ansid[9];
        long long int anstotal=0;
        for(int q=0;q<9;q++){
            ansid[q]=result[n-q-1].id;
            anstotal+=result[n-q-1].total;
        }
        sort(ansid,ansid+9);
        cout<<fixed<<setprecision(3)<<anstotal/9000.0<<endl;
        cout<<ansid[0];
        for(int q=1;q<9;q++){
            cout<<","<<ansid[q];
        }
        cout<<endl;
    }
}