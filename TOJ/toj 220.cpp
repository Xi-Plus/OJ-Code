#include<cstdio>
using namespace std;
int main(){
    int t;
    scanf("%d\n",&t);
    while(t--){
        int n;
        scanf("%d\n",&n);
        char c;
        int a=0,b=0,aa=0;
        for(int q=0;q<n;q++){
            scanf("%c",&c);
            if(c=='W'){
                a+=10+aa*5;
                aa=0;
            }
            else if(c=='L'){
                b+=10;
                if(aa<5)aa++;
            }
            else {
                a+=5;
                b+=5;
            }
        }
        printf("%d %d\n",a,b);
    }
    return 0;
}