#include <cstdio> //c¿é¤J¿é¥X
//#include <fstream>
//#include <sstream> //cmd
//#include <conio.h>  //if(kbhit())
//#include <windows.h>
//#include <ctime>  //time  srand(time(NULL));
#include <algorithm> //sort(n,n+k)  reverse
//#include <iomanip> //¤p¼Æ fixed<<setprecision or setw
//#include <cstdlib>  //system
//#include <cmath>
//#include <iostream>
using namespace std;
int main(){
    int n;
    while(~scanf("%d",&n)){
        int v[n];
        for(int q=0;q<n;q++)scanf("%d",&v[q]);
        sort(v,v+n);
        int min=2147483647;
        for(int q=0;q<=n-3;q++){
            for(int w=q+1;w<=n-2;w++){
                if(v[q]+v[w]>v[w+1]){
                    if(min>v[q]+v[w]+v[w+1])min=v[q]+v[w]+v[w+1];
                    break;
                }
            }
        }
        printf("%d\n",min);
    }
}