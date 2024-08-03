// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	string s;
	bool x=1;
	while(getline(cin,s)){
		int sz=s.size();
		for(int q=0;q<sz;q++){
			if(s[q]=='"'){
				if(x)cout<<"``";
				else cout<<"''";
				x^=1;
			}else {
				cout<<s[q];
			}
		}
		cout<<endl;
	}
}
