#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int>Fib[100000];
const int Max=500;
vector<int>::iterator j,k,out; 
int main(){
    Fib[0].push_back(0);
    Fib[1].push_back(1);
        for(int i=2;i<=Max;++i){
                int carry=0,sum;
                j=Fib[i-2].begin();
                k=Fib[i-1].begin();
                while(k!=Fib[i-1].end()){
                        if(j!=Fib[i-2].end())sum=(*j)+(*k);
                        else sum=*k;
                        Fib[i].push_back(sum%10000+carry);
                        carry=0;
                        if(sum/10000)carry=sum/10000;
                        j++;
                        k++;
                }
                if(carry)Fib[i].push_back(carry);
        }
        int n;
        while(cin>>n){
        bool flag=1;
                for(out=Fib[n].end()-1;out!=Fib[n].begin();out--){
            if(flag){
                printf("%d",*out);
                flag=0;
            }
            else printf("%04d",*out);
        }
                if(flag)printf("%d\n",*Fib[n].begin());
        else printf("%04d\n",*Fib[n].begin());
        }
}