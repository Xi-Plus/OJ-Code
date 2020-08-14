#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int a, b, c, d;
	cin>>a>>b>>c>>d;
	c-=a;
	d-=b;
	if(d<0){
		d+=60;
		c--;
	}
	if(c<0){
		c+=24;
	}
	cout<<"totally "<<c<<" hours and "<<d<<" minutes."<<endl;
}

