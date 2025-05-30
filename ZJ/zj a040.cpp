// By xiplus
#include <cmath>
#include <iostream>
using namespace std;
int main(){
	int a,b;
	while(cin>>a>>b){
		bool x=1;
		for(int q=a;q<=b;q++){
			int n=q,k=1;
			while(n/=10)k++;
			int sum=0;
			n=q;
			while(n){
				sum+=pow(n%10,k);
				n/=10;
			}
			if(q==sum){
				x=0;
				cout<<q<<" ";
			}
		}
		if(x)cout<<"none";
		cout<<endl;
	}
}
