#include <iostream>
using namespace std;
int main(){
	string s;
	int yes=0,no=0;
	for(int i=0;i<5;i++){
		cin>>s;
		if(s=="yes")yes++;
		else no++;
	}
	if(yes>no)cout<<"yes";
	else cout<<"no";
}
