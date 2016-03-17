// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int t;
	cin>>t;
	cin.ignore();
	cin.ignore();
	string s;
	char c;
	map<char,int> pri;
	pri['(']=3;
	pri['*']=2;
	pri['/']=2;
	pri['+']=1;
	pri['-']=1;
	while(t--){
		stack<char> v;
		while(getline(cin,s)&&s!=""){
			c=s[0];
			if('0'<=c&&c<='9')cout<<c;
			else if(c==')'){
				while(v.top()!='('){
					cout<<v.top();
					v.pop();
				}
				v.pop();
			}else{
				while(!v.empty()&&v.top()!='('&&pri[v.top()]>=pri[c]){
					cout<<v.top();
					v.pop();
				}
				v.push(c);
			}
		}
		while(!v.empty()){
			cout<<v.top();
			v.pop();
		}
		cout<<endl;
		if(t)cout<<endl;
	}
}
