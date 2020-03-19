#include <iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i+=n*2){
		for(int j=0;j<n&&i+j<m;j++)cout<<"R";
		for(int j=0;j<n&&i+n+j<m;j++)cout<<"W";
	}
}
