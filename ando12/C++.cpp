#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int x,y,z;
	cin>>x>>y>>z;
	vector<int> xl,yl;
	xl.push_back(0);
	xl.push_back(x);
	yl.push_back(0);
	yl.push_back(y);
	int q,d,a,xn=1,yn=1;
	cin>>q;
	while(q--){
		cin>>d>>a;
		if(d==0){
			xl.push_back(a);
			xn++;
		}else{
			yl.push_back(a);
			yn++;
		}
	}
	sort(xl.begin(),xl.end());
	sort(yl.begin(),yl.end());
	int xmin=2147483647,ymin=2147483647;
	for(int i=0;i<xn;i++){
		if(xl[i+1]-xl[i]<xmin)xmin=xl[i+1]-xl[i];
	}
	for(int i=0;i<yn;i++){
		if(yl[i+1]-yl[i]<ymin)ymin=yl[i+1]-yl[i];
	}
	cout<<xmin*ymin*z;
}
