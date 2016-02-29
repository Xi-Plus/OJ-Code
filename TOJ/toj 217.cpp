#include<cstdio>
using namespace std;
int main()
{
    const int mod=1000000007;
    int C[100001];
    C[0]=2;
    C[1]=2;
    for(int q=2;q<=100000;q++){
        if(q%2)C[q]=C[q-1];
        else C[q]=C[q-1]+C[q/2-1];
        if(C[q]>=mod)C[q]%=mod;
    }
    int B[100001];
    B[1]=4;
    for(int q=2;q<=100000;q++){
        B[q]=B[q-1]+C[q-1];
        if(B[q]>=mod)B[q]%=mod;
    }
    int A[100001];
    A[1]=2;
    for(int q=2;q<=100000;q++){
        A[q]=A[q-1]+B[q-1];
        if(A[q]>=mod)A[q]%=mod;
    }
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%d\n",A[n]);
    }
    return 0;
}