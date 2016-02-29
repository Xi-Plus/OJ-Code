#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        bool ans=0;
        if(x>0&&x%2&&y<=x+1&&y>=1-x)ans=1;
        else if(x<0&&x%2==0&&y>=x&&y<=-x)ans=1;
        else if(y>0&&y%2==0&&x<=y-1&&x>=-y)ans=1;
        else if(y<=0&&y%2==0&&x>=y&&x<=1-y)ans=1;
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}