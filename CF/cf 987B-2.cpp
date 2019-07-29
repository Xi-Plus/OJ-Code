#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y;
	cin>>x>>y;
	long double a=x*log(y);
	long double b=y*log(x);
	if(abs(a-b)<1e-6){
		cout<<"="<<endl;
	}else if(a>b){
		cout<<"<"<<endl;
	}else{
		cout<<">"<<endl;
	}
}
