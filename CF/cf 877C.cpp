#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	cout<<n/2*2+(n+1)/2<<endl;
	for(int q=2; q<=n; q+=2) {
		cout<<q<<" ";
	}
	for(int q=1; q<=n; q+=2) {
		cout<<q<<" ";
	}
	for(int q=2; q<=n; q+=2) {
		cout<<q<<" ";
	}
	cout<<endl;
}
