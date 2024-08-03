// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int t;
	string s;
	while(cin>>t){
		map<string,int> v;
		int n=0;
		while(t--){
			cin>>s;
			if(v[s]) cout<<"Old! "<<v[s]<<endl;
			else {
				v[s]=++n;
				cout<<"New! "<<n<<endl;
			}
		}
	}
}
