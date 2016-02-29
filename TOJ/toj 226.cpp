#include<iostream>
#include<algorithm>
using namespace std;
int v[100003];
int main()
{
    int t,n;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        bool x=0;
        int len=s.size();
        long long int sum=0;
        for(int q=0;q<len;q++){
            if(s[q]=='0')x=1;
            v[q]=s[q]-'0';
            sum+=v[q];
        }
        if(x&&sum%3==0){
            sort(v,v+len);
            for(int q=len-1;q>=0;q--)cout<<v[q];
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}