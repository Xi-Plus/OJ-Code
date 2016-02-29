//#include <bits/stdc++.h>
#include <iostream>
#define endl '\n'
using namespace std;
int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int t;
    cin>>t;
    cin.get();
    while(t--){
        string s;
        getline(cin,s);
        s="*"+s+"*";
        for(int q=0;q<s.size();q++){
            switch(s[q]){
                case '?':
                case '.':
                case '!':
                case ',':
                case ':':
                case ';':
                case '(':
                case ')':
                case '-':
                case '\'':
                case ' ':
                    s[q]='*';
                    break;
                case 'A' ... 'Z':
                    s[q]=(char)(s[q]-'A'+'a');
            }
        }
        int n=0,ans=0;
        while(n<s.size()){
            if(s[n]=='*'&&s[n+1]=='i'&&s[n+2]=='s'&&s[n+3]=='*'){
                n++;
                ans++;
            }
            else if(s[n]=='*'&&s[n+1]=='b'&&s[n+2]=='e'&&s[n+3]=='*'){
                n++;
                ans++;
            }
            else if(s[n]=='*'&&s[n+1]=='a'&&s[n+2]=='m'&&s[n+3]=='*'){
                n++;
                ans++;
            }
            else if(s[n]=='*'&&s[n+1]=='a'&&s[n+2]=='r'&&s[n+3]=='e'&&s[n+4]=='*'){
                n+=2;
                ans++;
            }
            else if(s[n]=='*'&&s[n+1]=='w'&&s[n+2]=='a'&&s[n+3]=='s'&&s[n+4]=='*'){
                n+=2;
                ans++;
            }
            else if(s[n]=='*'&&s[n+1]=='w'&&s[n+2]=='e'&&s[n+3]=='r'&&s[n+4]=='e'&&s[n+5]=='*'){
                n+=3;
                ans++;
            }
            else if(s[n]=='*'&&s[n+1]=='b'&&s[n+2]=='e'&&s[n+3]=='e'&&s[n+4]=='n'&&s[n+5]=='*'){
                n+=3;
                ans++;
            }
            else if(s[n]=='*'&&s[n+1]=='b'&&s[n+2]=='e'&&s[n+3]=='i'&&s[n+4]=='n'&&s[n+5]=='g'&&s[n+6]=='*'){
                n+=4;
                ans++;
            }
            n++;
        }
        cout<<ans<<endl;
    }
    return 0;
}