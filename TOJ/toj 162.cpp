#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    string s1,s2;
    int v[3][3];
    while(t--){
        cin.get();
        getline(cin,s2);    
        getline(cin,s1);
        for(int q=0;q<3;q++)for(int w=0;w<3;w++)cin>>v[q][w];
        int a=0,b=0;
        if(v[0][0]==0&&v[0][1]==0&&v[0][2]==0)a++;
        else if(v[1][0]==0&&v[1][1]==0&&v[1][2]==0)a++;
        else if(v[2][0]==0&&v[2][1]==0&&v[2][2]==0)a++;
        else if(v[0][0]==0&&v[1][0]==0&&v[2][0]==0)a++;
        else if(v[0][1]==0&&v[1][1]==0&&v[2][1]==0)a++;
        else if(v[0][2]==0&&v[1][2]==0&&v[2][2]==0)a++;
        else if(v[0][0]==0&&v[1][1]==0&&v[2][2]==0)a++;
        else if(v[0][2]==0&&v[1][1]==0&&v[2][0]==0)a++;
        if(v[0][0]==1&&v[0][1]==1&&v[0][2]==1)b++;
        else if(v[1][0]==1&&v[1][1]==1&&v[1][2]==1)b++;
        else if(v[2][0]==1&&v[2][1]==1&&v[2][2]==1)b++;
        else if(v[0][0]==1&&v[1][0]==1&&v[2][0]==1)b++;
        else if(v[0][1]==1&&v[1][1]==1&&v[2][1]==1)b++;
        else if(v[0][2]==1&&v[1][2]==1&&v[2][2]==1)b++;
        else if(v[0][0]==1&&v[1][1]==1&&v[2][2]==1)b++;
        else if(v[0][2]==1&&v[1][1]==1&&v[2][0]==1)b++;
        if(a+b==0)cout<<"Not yet"<<endl;
        else if(a==1&&b==0)cout<<s1<<endl;
        else if(a==0&&b==1)cout<<s2<<endl;
        else cout<<"Impossible"<<endl;
    }
    return 0;
}