#include <iostream>

using namespace std;

int main(){
	cout<<"#include<iostream>"<<endl;
	cout<<"using namespace std;"<<endl;
	cout<<"int main() {"<<endl;
	
	cout<<"int ";
	for(int i=1;i<=29; i++){
		cout<<"a"<<i<<", ";
	}
	cout<<"a30;"<<endl;
	cout<<"cin";
	
	for(int i=1;i<=30; i++){
		cout<<">>a"<<i;
	}
	cout<<";"<<endl;
	cout<<"bool yes=false;"<<endl;
	for(int i=1; i<=30; i+=6){
		for(int j=i; j<i+4; j++){
			cout<<"if(a"<<j<<"==a"<<j+1<<"&&a"<<j+1<<
				"==a"<<j+2<<") yes=true;"<<endl;
		}
	}
	for(int i=1; i<=18; i++){
		cout<<"if(a"<<i<<"==a"<<i+6<<"&&a"<<i+6<<
			"==a"<<i+12<<") yes=true;"<<endl;
	}
	cout<<"if(yes) cout<<\"Yes\"<<endl;"<<endl;
	cout<<"else cout<<\"No\"<<endl;"<<endl;
	
	cout<<"}"<<endl;
	
}