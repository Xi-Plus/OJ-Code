#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long int a[n+1];
    a[0]=0;
    int k;
    for(int q=1;q<=n;q++){
        cin>>k;
        a[q]=a[q-1]+k;
    }
    cin>>n;
    while(n--){
        int j,k;
        cin>>j>>k;
        if(j>k)j^=k^=j^=k;
        cout<<a[k]-a[j-1]<<endl;
    }
}