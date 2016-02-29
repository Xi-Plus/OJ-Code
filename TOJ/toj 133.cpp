#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long int q[n+1];
    q[0]=0;
    for(int i=1;i<=n;i++){
        cin>>q[i];
        q[i]=q[i]+q[i-1];
    }
    int a,b;
    cin>>n;
    while(n--){
        cin>>a>>b;
        if(a>b)a^=b^=a^=b;
        cout<<q[b]-q[a-1]<<endl;
    }
}