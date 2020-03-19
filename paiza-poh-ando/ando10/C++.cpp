#include <iostream>
using namespace std;
int main(){
	int n,a=1;
	cin>>n;
	while(n)a*=n--;
	cout<<a;
}
