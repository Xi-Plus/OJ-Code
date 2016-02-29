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
    long long int n;
    while(cin>>n){
        if(n<10)cout<<"Y"<<endl;
        else if(n<1000)cout<<"X"<<endl;
        else if(n<400000)cout<<"UV"<<endl;
        else if(n<700000)cout<<"VIS"<<endl;
        else if(n<1000000000)cout<<"IR"<<endl;
        else cout<<"R"<<endl;
    }
}