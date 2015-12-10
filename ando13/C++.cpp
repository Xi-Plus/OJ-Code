#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	long long ans=1;
	while(n){
		ans*=n;
		while(ans%10==0)ans/=10;
		ans%=1000000000000;
		n--;
	}
	cout<<ans%1000000000;
}
