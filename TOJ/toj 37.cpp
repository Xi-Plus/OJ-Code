#include <iostream>
using namespace std;
int main(){
    string s;
    while(getline(cin,s)){
        int l=s.size(),ans=1;
        bool x=0;
        for(int q=0;q<l;q++){
            if(s[q]==' '&&x){
                ans++;
                x=0;
            }
            else if(s[q]!=' ')x=1;
        }
        cout<<ans-!x<<endl;
    }
}