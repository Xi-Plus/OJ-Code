#include<iostream>
using namespace std;
int main()
{
    long long int k,x;
    while(cin>>k){
        if(k>10000||k<=0)while(1);
        long long int v[1000][2];
        int n=0;
        for(long long int y=k+1;true;y++){
            x=(k*y)/(y-k);
            if((k*y)%(y-k)==0){
                v[n][0]=x;
                v[n][1]=y;
                n++;
            }
            if(x<=y)break;
        }
        cout<<n<<endl;
        for(int q=0;q<n;q++){
            cout<<"1/"<<k<<" = 1/"<<v[q][0]<<" + 1/"<<v[q][1]<<endl;
        }
    }
    return 0;
}