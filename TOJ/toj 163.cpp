#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    string s;
    while(t--){
        cin>>s;
        bool x[16]={0};
        x[3]=s[0]-'0';
        x[5]=s[1]-'0';
        x[6]=s[2]-'0';
        x[7]=s[3]-'0';
        x[9]=s[4]-'0';
        x[10]=s[5]-'0';
        x[11]=s[6]-'0';
        x[12]=s[7]-'0';
        x[13]=s[8]-'0';
        x[14]=s[9]-'0';
        x[15]=s[10]-'0';
        x[1]=x[3] xor x[5] xor x[7] xor x[9] xor x[11] xor x[13] xor x[15];
        x[2]=x[3] xor x[6] xor x[7] xor x[10] xor x[11] xor x[14] xor x[15];
        x[4]=x[5] xor x[6] xor x[7] xor x[12] xor x[13] xor x[14] xor x[15];
        x[8]=x[9] xor x[10] xor x[11] xor x[12] xor x[13] xor x[14] xor x[15];
        for(int q=1;q<=15;q++)printf("%d",x[q]);
        printf("\n");
    }
    return 0;
}