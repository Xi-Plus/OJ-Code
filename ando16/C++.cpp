#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int m,t;
	cin>>m>>m;
	vector<int> x;
	while(m--){
		cin>>t;
		x.push_back(t);
	}
	sort(x.begin(),x.end());
	cin>>m;
	vector<int> y;
	while(m--){
		cin>>t;
		if(!binary_search(x.begin(),x.end(),t)){
			y.push_back(t);
		}
	}
	sort(y.begin(),y.end());
	if(y.size()){
		cout<<y[0];
		for(int i=1;i<y.size();i++){
			cout<<" "<<y[i];
		}
	}else{
		cout<<"None";
	}
}
