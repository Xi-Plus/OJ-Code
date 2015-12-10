#include <iostream>
using namespace std;
int main(){
	int n;
	string s;
	cin>>n;
	while(n--){
		cin>>s;
		cout<<s;
		if(n)cout<<"_";
	}
}
