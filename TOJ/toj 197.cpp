//#include <cstdio> //c¿é¤J¿é¥X
//#include <fstream>
//#include <sstream> //cmd
//#include <conio.h>  //if(kbhit())
//#include <windows.h>
//#include <ctime>  //time  srand(time(NULL));
#include <algorithm> //sort(n,n+k)  reverse
#include <iomanip> //¤p¼Æ fixed<<setprecision or setw
//#include <cstdlib>  //system
//#include <cmath>
#include <iostream>
using namespace std;
struct V{
    int x;
    int w;
    double a;
};
bool s(V a,V b){
    return a.a>b.a;
}
int main(){
    int n;
    double vv;
    while(cin>>n>>vv){
        V v[n];
        for(int q=0;q<n;q++){
            cin>>v[q].x>>v[q].w;
            v[q].a=(double)v[q].x/v[q].w;
        }
        sort(v,v+n,s);
        double ans=0;
        for(int q=0;q<n;q++){
            if(vv<=v[q].w){
                ans+=v[q].x*vv/v[q].w;
                break;
            }
            else {
                ans+=v[q].x;
                vv-=v[q].w;
            }
        }
        cout<<fixed<<setprecision(3)<<ans<<endl;
    }
}