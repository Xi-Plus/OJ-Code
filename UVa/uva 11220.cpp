#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	cin.ignore();
	cin.ignore();
	string s;
	for(int t=1; t<=T; t++) {
		cout<<"Case #"<<t<<":"<<endl;
		while(true){
			int i=0;
			getline(cin, s);
			if(s==""){
				break;
			}
			stringstream ss(s);
			while(ss>>s){
				if(s.size()>=i+1){
					cout<<s[i];
					i++;
				}
			}
			cout<<endl;
		}
		if(t<T){
			cout<<endl;
		}
	}
}
