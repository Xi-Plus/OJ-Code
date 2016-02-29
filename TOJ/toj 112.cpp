#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,a[11];
    cin>>n;
    for(int q=0;q<n;q++)cin>>a[q];
    for(int q=n-1;q>=0;q--)cout<<a[q]<<endl;
}