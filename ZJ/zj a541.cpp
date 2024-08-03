// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n;
	cin>>n;
	map<string,bool> v;
	string s;
	while(n--){
		cin>>s;
		v[s]=true;
	}
	cin>>n;
	while(n--){
		cin>>s;
		if(v[s])cout<<"yes"<<endl;
		else cout<<"no"<<endl;
		v[s]=true;
	}
}
