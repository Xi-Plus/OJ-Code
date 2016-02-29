//#include <cstdio> //c¿é¤J¿é¥X
//#include <fstream>
//#include <sstream> //cmd
//#include <conio.h>  //if(kbhit())
//#include <windows.h>
//#include <ctime>  //time  srand(time(NULL));
//#include <algorithm> //sort(n,n+k)  reverse
//#include <iomanip> //¤p¼Æ fixed<<setprecision or setw
//#include <cstdlib>  //system
//#include <cmath>
#include <iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        for(int q=0;q<n;q++){
            for(int w=0;w<q;w++)cout<<" ";
            for(int w=0;w<(n-q)*2-1;w++)cout<<(char)('A'+n-q-1);
            cout<<endl;
        }
    }
}